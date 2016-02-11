#include<cs50.h>
#include<stdio.h>
int main()
{
    int n;
    int i,j;
    do
    {
        printf("height :");
        n=GetInt();
    }
    while(n>23 || n<0);
 
    for(i=0;i<n;i++)
    { 
        for(j=0;j<(n-1-i);j++)
        {
            printf(" ");
        }
        for(j=(n-1-i);j<=n;j++)
        {
             printf("#");
        }
        printf("\n");
   }
   return 0;
}