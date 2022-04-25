#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  Mohamed Yasser Mohamed


/************************************************************************
* what do I want to do?
* 1- read client's data: (name, age, id);
* 2- write these data in data.txt;
* 3- read these data from data.txt;
* 4- print these data on console;
************************************************************************/

const char* file_name = "data.pdf"; 
const char* format_write = "{\n\t\"Name\": \"%s\",\n\t\"Age\": \"%i\",\n\t\"Id\": \"%llu\"\n}\n";
const char* format_read =  "{\n\t\"Name\": \"%[^\"]\",\n\t\"Age\": \"%i\",\n\t\"Id\": \"%llu\"\n}";

typedef struct
{
    char name[21];
    unsigned char age;
    unsigned long long int id;
}client;


int main()
{
    /* local variables section: */
    client c1;
    FILE* file_pointer;
    char data_buffer[sizeof(c1)];

    puts("***************************************************************************");
    /* 1- read data from user: */
    puts("Please enter you data\n");

    printf("Your name is.......: ");
    fflush(stdin);
    fgets(c1.name, sizeof(c1.name), stdin);
    //c1.name[strlen(c1.name)-1] = '\0';

    printf("Your age is........: ");
    fflush(stdin);
    scanf("%i", &c1.age);

    printf("Your national id is: ");
    fflush(stdin);
    scanf("%llu", &c1.id);
    /*-----------------------------------------------------------------------------------------------*/
    /* 2- write data in a text file: */
    file_pointer = fopen(file_name, "a");
    printf("file_pointer = %i\n", file_pointer);
    if(NULL == file_pointer)
    {
        printf("I can not create a txt file for you!!\n");
    }
    else
    {
       fprintf(file_pointer, format_write, c1.name, c1.age, c1.id);
       fseek(file_pointer, 0, SEEK_SET);
        
    }
    
    /*-----------------------------------------------------------------------------------------------*/
    /* 3- read data from txt file: */
    file_pointer = fopen(file_name, "r");
    if(NULL == file_pointer) //check if you can not open file:
    {
        puts("Can not open/find your text file!!\n");
        return 1;
    }
    else
    {
       fscanf(file_pointer, format_read, &c1.name,&c1.age, &c1.id);
    }
    
    

    /*-----------------------------------------------------------------------------------------------*/
    puts("----------------------------------------------------------------------------");
    puts("Your data are:\n");
    printf("Your name is: %s\n", c1.name);
    printf("Your age is : %i\n", c1.age);
    printf("Your id is  : %llu\n", c1.id);




    puts("***************************************************************************");
    return 0;
}