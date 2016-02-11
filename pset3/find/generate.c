/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
        
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define LIMIT 65536
 
int main(int argc, string argv[])
{
    // TODO: check if the user printed less than two or more than three arguments
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }
 
    // TODO: convert the firdt argument :n to an integer, since argv[1]is a string 
    int n = atoi(argv[1]);
 
    // TODO: check if the user printed the optional argument s to generate randomly 
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }
 
    // TODO: print a random number less tha LIMIT which is 655536
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }
 
    // that's all folks
    return 0;
}