/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
        
#include <cs50.h>
 
#include "helpers.h"
 
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n>0)
    {
     int max=n-1,min=0;
     while(min<=max)
     {
        if(values[(max+min)/2]==value)
            return true;
        else if(values[(max+min)/2]<value)
        {
            min=(max+min)/2+1;
        }
        else if (values[(max+min)/2]>value)
        {
            max=(max+min)/2-1;   
        }
     }
         
    }
    return false;
}
 
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int lowerindex;
    int temp;//to permute the values
    for (int i=0;i<n-1;i++)
    {
       lowerindex=i;
       for(int j=i+1;j<n;j++)
       {        
          if(values[j]<values[lowerindex])
          {
            lowerindex=j;
          }  
       } 
        temp=values[i];
        values[i]=values[lowerindex];
        values[lowerindex]=temp;
    }
}