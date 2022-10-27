#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//function to check if a char is lowercase english letter
int check_small(char a)
{
   if(a<='z'&& a>='a')
      return 1;

   return 0; 
}

int main()
{
   char key[100],message[1000];//key and message

   //reading the key
   printf("Enter the key:\n");
   scanf("%[^\n]%*c",key);
   
   int i,j;//loop variables

   int map_arr[26];//array used to map the alphabets of the key to corrseponding alphabet
                   //in this array the i-th element refers to the i+1 th alphabet (eg. 0==a,1==b...)
                   //the value stored at the i-th element be j which indicates the i+1 th alphabet will decode to j+1 th alphabet 

   
   //initializng the map_arr with -1 which means for the particular alphabet no mapping has been done
   for(i=0;i<26;i++)
   {
     map_arr[i]=-1;
   }

   j=0;//j indicates that for the upcoming character in key we will map that to j+1 th alphabet
       //we begin with j=0 which is 'a'

   //looping over the key string
   //we check if the character is lowercase english letter
   //if it is we check if there is already a mapping for it
   //if not we map it to j-th alphabet and increase j
   for(i=0;i<strlen(key);i++) 
   {
      if(check_small(key[i]))
      {
          if(map_arr[key[i]-'a']==-1)
          {
              map_arr[key[i]-'a']=j;
              j=j+1;
          }
       }
    }

   //taking the user input message 
   printf("Enter the message:\n");
   scanf("%[^\n]%*c",message);


   //we loop through the message and for lowercase english letters we replace it with its decoded key
   for(i=0;i<strlen(message);i++)
   {
       if(check_small(message[i]))
       {
           message[i]='a'+map_arr[message[i]-'a'];
       }
   }

  
   //printing the final answer
   printf("Decoded message: %s\n",message);
}
