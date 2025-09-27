#include<stdio.h>
#include<stdint.h>
#include<string.h>

//accepting command line arguments
int main(int argc, char *argv[])
{
    //making sure there is 2 command line arguments
    if (argc != 2)
    {
        printf("Usage: ./pdf pdfname.pdf");
        return 1;
    }


    /*creating a reading pointer 'read' and opening the file with fopen and
    the filename that you got from argv*/
    
    FILE *read = fopen(argv[1],"r" );
    if (read == NULL) 
    {printf("Cannot open file.\n");
    return 1;}

    //datatype for exactly one byte
    uint8_t buffer[4];
       

     uint8_t check[4] = {0x25, 0x50, 0x44, 0x46};

     //reading 4 bytes of size uint8_t from read to buffer 
     //buffer needs to be an address
     fread(buffer,sizeof(uint8_t),4,read);
        int flag = 0;
    for(int i=0;i<4;i++)
    {

        if(check[i] != buffer[i]) {flag = 1; break;}

    }
    
    if(flag == 0 ) {printf("\n PDF FILE"); }
    else {printf("\nNOT PDF FILE");}
    
    fclose(read);
    return 0;
}
