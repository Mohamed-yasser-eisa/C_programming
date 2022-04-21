#include <stdio.h>
#include <stdlib.h>


typedef unsigned char Byte;
typedef unsigned short Uint16;

/*Also we can give a name to pointer datatype as follow:*/
typedef char* pointer_char;
typedef int*  pointer_int;



int main()
{
    puts("************************************************");
    puts("typedef is a keyword which is used to give a new name to datatype.\n");
    puts("--> Syntax is as follow:");
    puts("\ttypedef\told_datatype\tnew_name;\n");

    Byte x = 255;
    printf("X = %i\n", x);



    puts("************************************************");
    return 0;
}