#include <stdio.h>
#include <stdlib.h>



int main()
{
    puts("****************************************************************");
    puts("Pointer to int, and use of operators: '&', '*' :\n");
    int x1 = 50;
    int *ptr1 = &x1;
    printf("x1      = %i\n", x1);
    printf("&x1     = %i\n", &x1);
    puts("-------   --------    -------");
    printf("ptr1    = %i\n", ptr1);//pointer to int
    printf("*ptr1   = %i\n", *ptr1);//dereference pointer to int = x1
    printf("&*ptr1  = %i\n", &*ptr1);//pointer to int x1, returns address of x1;
    puts("-------   --------    -------");
    printf("&ptr1   = %i\n", &ptr1);//pointer to pointer to int
    printf("*&ptr1  = %i\n", *&ptr1); //dereference pointer to pointer to int = pointer to int
    printf("**&ptr1 = %i\n", **&ptr1);//dereference pointer to pointer to int = value in int x1

    puts("-----------------------------------------------------------------");
    puts("Wild pointer:\n");

    /* wild pointer is any uninitialized pointer*/
    /* never apply dereference operator to wild pointer, it causes run-time error (segmentation fault)*/
    
    int *ptr2; //uninitialized pointer = wild pointer.

    printf("Address in ptr2 = %i\n", ptr2);//garbage value is stored in ptr2.

    puts("-----------------------------------------------------------------");
    puts("Access and step of pointers:\n");
    
    /* access and step of pointer depend on sizeof(data type) that the pointer points to */

    int x2 = 10;
    short x3 = 210;
    char x4 = 100;

    int *ptr3 = &x2;
    short *ptr4 = &x3;
    char *ptr5 = &x4;

    printf("ptr3   = %i\n", ptr3);//base address in ptr3
    printf("*ptr3  = %i\n", *ptr3);//access of ptr3 is 4 bytes
    printf("++ptr3 = %i\n", ++ptr3);//step of ptr3 is 4 bytes
    puts("-------   --------    -------");
    printf("ptr4   = %i\n", ptr4);//base address in ptr4
    printf("*ptr4  = %i\n", *ptr4);//access of ptr4 is 2 bytes
    printf("++ptr4 = %i\n", ++ptr4);//step of ptr4 is 2 bytes
    puts("-------   --------    -------");
    printf("ptr5   = %i\n", ptr5);//base address in ptr5
    printf("*ptr5  = %i\n", *ptr5);//access of ptr5 is 1 bytes
    printf("++ptr5 = %i\n", ++ptr5);//step of ptr5 is 1 bytes
    
    puts("-----------------------------------------------------------------");
    puts("Operations on pointers:\n");

    /* increment or decrement pointer = increment or decrement one step from its base address */

    int *ptr6 = 1500;//assume that '1500' is a memory location
    int *ptr7 = 2500;//assume that '2000' is a memory location

    printf("ptr6   = %i\n", ptr6);//base address in ptr6
    printf("++ptr6 = %i\n", ++ptr6);//increment sizeof(int) to base address of ptr6
    ptr6 = 1500;
    printf("--ptr6 = %i\n", --ptr6);//decrement sizeof(int) from base address of ptr6
    ptr6 = 1500;
    puts("-------   --------    -------");
    /* subtract value from pointer means: "subtract number of steps from base address": */
    printf("ptr6   = %i\n", ptr6);//base address in ptr6
    printf("ptr6-4 = %i\n", ptr6-4);
    puts("-------   --------    -------");

    /* Subtract pointer from another pointer returns number of steps between them */
    /* If we know steps between poinrters then we can get to any of them from address of the other one*/
    /* The two pointers must be of the same type */

    printf("ptr7-ptr6 = %i bytes\n", ptr7-ptr6);
    ptr6 = 1500;
    ptr7 = 2500;
    puts("-------   --------    -------");

    /* Adding value to pointer is allowed, and it means: "add to base adress number of steps" */
    printf("ptr6   = %i\n", ptr6);//base address in ptr6
    printf("ptr6+4 = %i\n", ptr6+4);
    ptr6 = 1500;
    ptr7 = 2500;
    puts("-------   --------    -------");

    /* Adding pointer to pointer is not allowed, because it has no meanning or useful use. */

    puts("-----------------------------------------------------------------");
    puts("Casting with pointers:\n");

    /* Type casting with pointers will affect access and step of pointer only. */
    /* Type casting with pointers never affect the address stored in it. */

    int x5 = 0xf5f4f6f3; // size of int = 4 bytes
    int *ptr8 = &x5;
    printf("(int) x5      = %X\n", x5);
    printf("*(int*)ptr8   = %X\n", *(int*)ptr8);
    printf("*(short*)ptr8 = %X\n", *(short*)ptr8);
    printf("*(char*)ptr8  = %X\n", *(char*)ptr8);

    puts("-----------------------------------------------------------------");
    puts("NULL pointers:\n");

    /* (NULL = '\0' = 0)*/
    /* It's a good practice to always assign (NULL) to any pointer that you will not assign it to variable now */
    /* Never dereference a (NULL) pointer, it will give you run-time error. */

    int *ptr9 = NULL;
    printf("ptr9 = 0X%p\n", ptr9);

    puts("-----------------------------------------------------------------");
    puts("Subscriptor operator [] with pointers:\n");

    /* ptr[0] = *(ptr+0) */
    /* ptr[1] = *(ptr+1) */
    /* ptr[2] = *(ptr+2) */
    
    /* You can not type cast pointer with subscriptor operator. */

    x5 = 0xf5f4f6f3; // size of int = 4 bytes
    ptr9 = &x5;

    printf("x5             = 0X%X\n", x5);
    printf("*ptr9          = 0X%X\n", *ptr9);
    printf("ptr9[0]        = 0X%X\n", ptr9[0]); // ptr9[0] = *(ptr9 + 0)
    printf("ptr9[1]        = 0X%X\n", ptr9[1]); //garbage value // ptr9[1] = *(ptr9 + 1)

    puts("\nYou can not type cast pointers with subscriptor operator as follow: ");
    printf("(char*)ptr9[0] = 0X%X\n", (char*)ptr9[0]); //you can not cast pointers with subscriptor operator
    
    puts("-----------------------------------------------------------------");
    puts("Arithmatic operators (++) with (*) in pointers:\n");

    /* (++) and (*) are unary operators of the same precedence, but they will be executed from right to left. */
    x5 = 0xf5f4f6f3; // size of int = 4 bytes
    ptr9 = &x5;
    printf("*ptr9++ = 0X%p\n", *ptr9++); // (++) will be executed first, but will increment in the next line.
    printf("*++ptr9 = 0X%p\n", *++ptr9); // (++) will be executed first, and will increment ptr by one step.

    puts("-------   --------    -------");


    puts("****************************************************************");
    gets((char*)ptr1);//wait user enter any char the exit
    return 0;
}