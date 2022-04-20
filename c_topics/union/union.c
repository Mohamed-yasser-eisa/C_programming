#include <stdio.h>
#include <stdlib.h>


union Data
{
    char x;
    short y;
    int z;
    double arr[5];
};



int main()
{
    puts("**************************************************");
    puts("--> union is a user defined datatype that allows user to store different datatypes\n"
    "in the same memory location.");

    union Data data;
    data.x = 'a';
    printf("data = %c\n", data.x);
    printf("size of data = %i\n", sizeof(data));
    

    
    

    puts("--------------------------------------------------");
    puts("Notes:\n");
    

    puts("");
    puts("**************************************************");
    return 0;
}