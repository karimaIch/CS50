#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
 
int main(int argc , string argv[])
{
    if((argc==1)|| (argc >2))
    {
        printf("error!,only set one key \n");
        return 1;
    }
    else
    {
        for(int i=0;i<strlen(argv[1]);i++)
        {
            if(!isalpha(argv[1][i]))
            {
                printf("your key must be string\n");
                return 1;
            }
        }  
        string message=GetString();
        int j=0;//j is the index of the key
             for(int i=0;i<strlen(message);i++)
                {
                    if (isalpha(message[i]))
                    {
                    int k= j%strlen(argv[1]);
                    j++;//only increment j if the caracter is alpabet
                    int p;
                    int ki;
                    int c;
                    if(isupper(argv[1][k]))
                      {
                        ki=argv[1][k]-'A';
                      }
                    else
                      {
                         ki=argv[1][k]-'a';
                      }
                        if(isupper(message[i])) 
                        {
                            p=message[i]-'A';                   
                            c=(p+ki)%26;
                            printf("%c",(c+'A'));                             
                        }
                         else
                         { 
                            p=message[i]-'a';
                            c=(p+ki)%26;
                            printf("%c",(c+'a'));                    
                         }                  
                    }
                    else
                    {
                         printf("%c",message[i]);
                    }
                         
               }
               printf("\n");
    }
}