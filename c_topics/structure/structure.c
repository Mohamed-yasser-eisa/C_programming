#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car
{
    int x;
    int y;
    short z;
}f;

struct student
{
    int Id;
    float GPA;
    char name[10];
    short int day[4];
};

int i=0;

int main()
{
    puts("**************************************************");
    struct car w;
    printf("w    = %i\n", w);//Unlike array, name of struct = value of first member in it.
    printf("w.x  = %i\n", w.x);//value of first element.
    printf("&w   = %i\n", &w);//like array, address of struct = address of first member in it.
    printf("&w.x = %i\n", &w.x);//address of member 'x' in the struct.
    printf("&w.y = %i\n", &w.y);//address of member 'y' in the struct.
    printf("&w.z = %i\n", &w.z);//address of member 'z' in the struct.

    puts("--------------------------------------------------------------");
    struct student st1;
    
    puts("Please enter student Id:");
    scanf("%i", &st1.Id);
    puts("Please enter student GPA:");
    scanf("%f", &st1.GPA);
    puts("Please enter student Name:");
    fflush(stdin);
    gets(st1.name);
    printf("\nStudent Id = %i\n", st1.Id);
    printf("Student GPA = %0.3f\n", st1.GPA);
    printf("Student Name = %s\n", st1.name);

    puts("--------------------------------------------------------------");
    printf("st1.name = %i\n", st1.name);//Name of array is a pointer to char
    printf("st1.name+1 = %i\n", st1.name+1);//step of array name = 1 byte
    printf("st1.&name = %i\n", &st1.name);//&Name of array is pointer to array
    printf("st1.name+1 = %i\n", &st1.name+1);//step of pointer to array = 10 bytes

    puts("--------------------------------------------------------------");
    printf("&st1.name[0]     = %i\n", &st1.name[0]);
    printf("&st1.name[1]     = %i\n", &st1.name[1]);
    printf("&st1.name[0] + 1 = %i\n", &st1.name[0]+1);

    puts("--------------------------------------------------------------");
    puts("Please enter date of 4 days:");
    for(i=0; i<4; ++i)
    {
        scanf("%i", &st1.day[i]); //&st1.day+i
    }
    puts("Days are:");
    for(i=0; i<4; ++i)
    {
    printf("%i\n", *(st1.day+i));  //st1.day[i]
    }

    puts("--------------------------------------------------------------");
    /*initializing struct members of type array: */
    struct student st2 = {10,2.5, {'M','o','h','a','m','e','d'}, {15,25,35,45}};
    puts("st2 members are:\n");
    printf("Id  = %i\n", st2.Id);
    printf("GPA = %f\n", st2.GPA);
    printf("Days = {");
    for(i=0; i<4; ++i)
    {
    printf(" %i,", *(st2.day+i));  //st2.day[i]
    }
    puts("\b }");
    printf("name = %s\n", st2.name);
    puts("----     ----    ----    ----    ----");
    struct student st3 = {50,3, "Ali Moham", {1,2,3,4}};

    strcpy(st3.name, "Mahmoud");//copy string in array of chars


    puts("st3 members are:\n");
    printf("Id  = %i\n", st3.Id);
    printf("GPA = %f\n", st3.GPA);
    printf("Days = {");
    for(i=0; i<4; ++i)
    {
    printf(" %i,", *(st3.day+i));  //st3.day[i]
    }
    puts("\b }");
    printf("name = %s\n", st3.name);
    

    

    puts("**************************************************");
    return 0;
}

