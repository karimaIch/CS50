/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    if((atoi(argv[1])<1) ||(atoi(argv[1])>100))
    {
        //printf("must be positive integer less or equal to 100\n");
        return 0;
    } 
    int n=atoi(argv[1]);
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    BITMAPFILEHEADER bfo = bf;
    BITMAPINFOHEADER bio = bi;   
    
    // write outfile's BITMAPINFOHEADER
    if(n==1){
    bfo = bf;
    bio = bi; 
    }
    else
    {
    
    bio.biWidth=n*bi.biWidth;
    bio.biHeight=n*bi.biHeight;   
    bio.biSizeImage=((((bio.biWidth *bio.biBitCount) + 31) & ~31) / 8) * abs(bio.biHeight);
    bfo.bfSize = bf.bfSize - bi.biSizeImage + bio.biSizeImage;  
          
    } 
    // determine padding for scanlines 
    int padding = (4-(bi.biWidth*sizeof(RGBTRIPLE)) % 4) % 4;  
    int padding2=(4 - (bio.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
             // write outfile's BITMAPFILEHEADER  
                 fwrite(&bfo, sizeof(BITMAPFILEHEADER), 1, outptr);
            
             //write outfile's BITMAPINFOHEADER
                fwrite(&bio, sizeof(BITMAPINFOHEADER), 1, outptr); 
            
    RGBTRIPLE* tab = malloc(bio.biWidth * sizeof(RGBTRIPLE));
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
            int ele = 0;
        // iterate over pixels in scanline    
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                 
                // write RGB triple to outfile
                for(int o=0;o<n;o++)
                {
                    tab[ele++] = triple;
                }
            }
        
        // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
            
                for(int h=0;h<n;h++)
                  {
                    fwrite(tab, sizeof(RGBTRIPLE), bio.biWidth, outptr);                
                     
                     for (int a = 0; a < padding2; a++)
                        fputc(0x00, outptr); 
                  }  
    }
  free(tab);
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
