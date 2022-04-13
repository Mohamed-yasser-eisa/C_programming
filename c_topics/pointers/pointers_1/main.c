#include <stdio.h>
#include <stdlib.h>

void swap(int **ptr1,int **ptr2)
{
    int *temp;
    temp = *ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}

int main()
{
    /* understanding what is the (&) operator */
    /* the ampersand (&) operator works as a pointer to memory location*/
    int var1 = 10;
    //the (&) works as a pointer to var1, so it returns the address of var1 as follow:
    printf("Address of var1 = %i\n", &var1);
    //As (&) works as a pointer, so we can use dereference operator with
    //it to return value stored in var1 as follow:
    printf("Value in var1 = %i\n", *&var1);

    /**===========================================================**/
    puts("*************** (EX:1) ****************");
    int x=50, y;
    int *ptr = &x;
    y = (*ptr)++;
    printf("ptr = %i\n", ptr);
    printf("x = %i\n", x);
    printf("y = %i\n", y);
    puts("*************** (EX:2) ****************");
    int x2=50, y2=100;
    int *const ptr2 = &x2;
    int **ptr3 = &ptr2;
    *ptr3 = &y2;
    printf("ptr2 = %i\n", *ptr2);
    puts("*************** (EX:3) ****************");
    const x3 = 20;
    int *const ptr4 = &x3;
    (*ptr4)++;
    printf("X3 = %i\n", x3);
    const int *ptr5 = &x;
    //*ptr5 = 10;
    //(this gives an error, as ptr5 is pointer to constant int)
    printf("X3 = %i\n", x3);
    puts("*************** (EX:4) ****************");
    int x5=255, y5;
    int *ptr6=&x5;
    printf("ptr6 = %i\n", ptr6); //2686704
    printf("&x5 = %i\n", &x5); //2686704
    printf("x5 = %i\n", x5);
    y5=*ptr6++;
    printf("ptr6 = %i\n", ptr6);
    printf("&x5 = %i\n", &x5);
    printf("x5 = %i\n", x5);
    printf("y5 = %i\n", y5);
    printf("*ptr6 = %i\n", *ptr6);
    ptr6=&x5;
    y5=*++ptr6;
    printf("ptr6 = %i\n", ptr6);
    printf("x5 = %i\n", x5);
    printf("y5 = %i\n", y5);
    printf("*ptr6 = %i\n", *ptr6);
    ptr6=&x5;
    (*ptr6)++;
    printf("ptr6 = %i\n", ptr6);
    printf("&x5 = %i\n", &x5); //2686704
    printf("x5 = %i\n", x5);

    puts("*************** (EX:5) ****************");
    int x6=100, y6=200;
    int *ptr7=&x6;
    int *ptr8=&y6;
    puts("Before swapping:");
    printf("X6 = %i\nY6 = %i\n",*ptr7,*ptr8);
    swap(&ptr7,&ptr8);
    puts("After swapping:");
    printf("X6 = %i\nY6 = %i\n",*ptr7,*ptr8);
    puts("*************** (EX:6) ****************");
    int x7=100;
    int *ptr9=&x7;
    printf("X7 = %i\n", x7);
    printf("&X7 = %i\n", &x7);//pointer to x7
    printf("ptr9 = %i\n", ptr9);
    printf("*ptr9 = %i\n", *ptr9);
    printf("&ptr9 = %i\n", &ptr9);
    printf("*&ptr9 = %i\n", *&ptr9);//pointer to pointer
    printf("*&ptr9 = %i\n", **&ptr9);//pointer to pointer to int
    puts("*************** (EX:7) ****************");
    puts("*************** (EX:8) ****************");
    puts("*************** (EX:9) ****************");
    return 0;
}


