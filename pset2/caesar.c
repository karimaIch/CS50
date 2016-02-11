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
        int k=atoi(argv[1]);
        if (k>0)//we cant test thekey before converting it to an integer
            {
             string message=GetString();
             for(int i=0;i<strlen(message);i++)
                {
                    if (isalpha(message[i]))
                    {
                        if(isupper(message[i])) 
                        {
                            int p=message[i]-'A';//the index of the caracter
                            int c=(p+k)%26;
                            printf("%c",(c+'A'));//c gives us the index of the caracter so we ad the ascii code of 'A'TO GET IT POSITION IN THE ASCII TABLE
                        }
                         else if(islower(message[i]))
                         { 
                            int p=message[i]-'a';                      
                            int c=(p+k)%26;
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
        else
            {
             printf("error! your key must be a positive integer \n");
             return 1;
            }
        return 0;
    }
}