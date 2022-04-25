#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
* Steps to write a txt file:
*   1- make sure that you have a txt file in your directory to write on it.
*   2- inclide <stdio.h> to use functions that help you interface with txt file.
*   3- create a pointer of type (FILE) to point to your txt file.
*   4- write on the txt file using (fprintf();) function.
*
*****************************************************************************************/



int main()
{
    puts("************************************************");
    char* fileName = "data.txt";
    char data[100];
    /* first you need to create a pointer of type FILE, to hold location of your txt file: */
    FILE* filePointer = fopen(fileName, "w"); //file pointer which is set to write only.

    /*check if you can not open file: */
    if(NULL == filePointer)
    {
        printf("Can not open/find %s file!!\n", fileName);
        return 1;
    }

    int i=0;
    for(i=0; i<2;++i)
    {
        printf("(%i)Please enter your name: ", i);
        fflush(stdin);
        gets(data);
        fprintf(filePointer, "%s\n",data);
        /* Or use fputs(); to write string without paces: */
        //fputs(data, filePointer);
    }
       
    
    /*now let's close our text file: */
    fclose(filePointer);

    puts("************************************************");
    return 0;
}