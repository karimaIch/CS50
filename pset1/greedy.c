#include<cs50.h>
#include<stdio.h>
#include<math.h>
int main()
{
    float change;//money we want to convert
    int number_coin=0;
    int quotient;//quotient is an int that contain the integer quotient of division of change by 25,10,5,1
    float rest;
    printf("o hai ! ");
    do
    {
        printf("how much owed ?");
        change=GetFloat();
    }
    while(change<0);
    change*=100;
    change=round(change);
    if(change>=25)
    {
        quotient=change/25;
        number_coin+=quotient;
        rest=change-quotient*25;
        change=round(rest);
    }
   if(change>=10 && change<25)
   {
        quotient=change/10;
        number_coin+=quotient;
        rest=change-quotient*10;
        change=round(rest);
   }
   if(change>=5 && change<10)
   {
        quotient=change/5;
        number_coin+=quotient;
        rest=change-quotient*5;
        change=round(rest);      
   }
   if(change>=1 && change<5)
   {
        number_coin+=change;
        rest=change-quotient*1;
        change=round(rest); 
   }
         
    printf("%d\n",number_coin);       
    return 0;
}