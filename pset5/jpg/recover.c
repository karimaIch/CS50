/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdint.h>
typedef uint8_t  BYTE;

int main(int argc, char* argv[])
{

    FILE* file = fopen("card.raw", "r");
    if (file == NULL)
    {
        printf("Could not open \n");
        return 2;
    }
    
        int nbimage=0;
        BYTE buffer[512];
        char title[8];
        FILE* img=NULL;
        
    //read 512byte
       while(fread(buffer,sizeof(BYTE), 512, file)==512)
        {  
           
            if( (buffer[0]==0xff) && (buffer[1]==0xd8) && (buffer[2]==0xff) && ((buffer[3]==0xe0)||(buffer[3]==0xe1)) )
            {
                //nbimage;
                if(img==NULL)
                {
                    sprintf(title,"%3.3d.jpg",nbimage);
                    img = fopen(title, "a");
                    if(img==NULL)
                    {
                        printf("could npt open the file\n");
                        return 2;
                    }
                    fwrite(buffer,sizeof(BYTE), 512,img);
                }
                else
                {
                    fclose(img);
                    sprintf(title,"%3.3d.jpg",++nbimage);
                    img = fopen(title, "a");
                    if(img==NULL)
                    {
                        printf("could npt open the file\n");
                        return 2;
                    }
                   fwrite(buffer,sizeof(BYTE), 512,img);                
                }
           }
           else  if(img!=NULL)
                {
                    fwrite(buffer,sizeof(BYTE), 512,img);
                }
                                 
        }
            if(img!=NULL)
            {
                fclose(img);
            } 


    fclose(file);
    return 0;

}
