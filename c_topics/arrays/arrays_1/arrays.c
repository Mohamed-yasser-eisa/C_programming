#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int arr_global[SIZE];//default values are zeros. Like global variables;
const int arr_const_global[SIZE];//default values are zeros. Like const global variables;


/*name of the array is a pointer to first element, so we recive pointer in pointer to print array elements:*/
void print_array(int *ptr);


int main()
{
    puts("**************************************************");
    puts("Initializing array elemets:\n");

    puts("(1) You can initialize array elements one by one as follow:");
    /* (1) You can initialize array elements one by one as follow: */
    int arr1[SIZE];
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;
    arr1[3] = 40;
    arr1[4] = 50;

    puts("(2) You can initialize array elements in single line as follow:");
    /* (2) You can initialize array elements in single line as follow: */
    int arr2[SIZE] = {1,2,3,4,5};//you can do this: int arr2[]={1,2,3,4,5}; compiler will detect array size from initialization

    puts("(3) You can initialize array elements by designation as follow:");
    /*No need to bother about order atall;*/
    /*No need to bother about enteries by zeros, (other elements will be zeros);*/
    /*length of array in case of designated array can be determined from largest index in designation.*/
    int arrr[SIZE] = {arrr[4]=50, arrr[2]=10, arrr[3]=30};



    puts("**************************************************");
    puts("Default values inside arrays:\n");

    puts("-->(1) Global arrays are initialized by zeros by default:");
    printf("Global uninitialized array:(");
    print_array(arr_global);

    puts("-->(2) Const global arrays are initialized by zeros by default:");
    printf("Const global uninitialized array:(");
    print_array((int*)arr_const_global);//casting array name to be (int*)as function arguments type instead on (int *cost).

    puts("-->(3) Local arrays are initialized by garbage by default:");
    printf("Local uninitialized array:(");
    int arr3[SIZE];
    print_array(arr3);

    puts("-->(4) Static local arrays are initialized by zeros by default:");
    printf("Static local uninitialized array:(");
    static int arr4[SIZE];
    print_array(arr4);

    puts("-->(5) Const local arrays are initialized by garbage by default:");
    printf("Const local uninitialized array:(");
    const int arr5[SIZE];
    print_array((int*)arr5);//casting array name to be (int*)as function arguments type instead on (int *cost).

    puts("-->(6) If you initialized only one element of the array, other elements' value in zero by default:");
    printf("One initialized eleemnt of local array:(");
    int arr6[SIZE] = {10};
    print_array(arr6);

    puts("**************************************************");
    puts("Name of array:\n");
    puts("--> Name of an array is a \"const pointer\" to first element in the array, and \n"
    "\tinitialized with fist element's address\n");
    puts("--> Step of array name = sizeof(data type of its elements). As follow:");
    char aChar[SIZE];
    short aShort[SIZE];
    printf("aChar    = %i\n", aChar);
    printf("aChar+1  = %i\n", aChar+1);
    printf("aShort   = %i\n", aShort);
    printf("aShort+1 = %i\n", aShort+1);
    printf("aInt     = %i\n", arr6);
    printf("aInt+1   = %i\n", arr6+1);
    puts("");
    puts("--> arr+2  = &arr[2];\tBUT ((((((( &arr+2 != &arr[2] )))))))");
    puts("--> arr[3] = *(arr+3);");
    puts("--> &arr = arr;");
    puts("--> &arr+1 = arr + sizeof(array); because step of (&arr +1) is equal to size of array;");

    puts("**************************************************");
    puts("Size of an array:\n");
    puts("Array size = number of elements * sizeof(data type)\n");
    printf("Size of: char arr[5]  = %i bytes.\n", sizeof(aChar));
    printf("Size of: short arr[5] = %i bytes.\n", sizeof(aShort));
    printf("Size of: int arr[5]   = %i bytes.\n", sizeof(arr2));

    puts("**************************************************");
    puts("Scan and print array elements:\n");
    puts("We use for loop to scan and print array elements.\n");
    puts("please enter 5 int for array elements:");
    int i=0;
    for(i=0; i<SIZE; ++i)
    {
        scanf("%i", &arr2[i]); //&(arr2+i);
    }
    puts("You entered elements:\nArray elements = ");
    for(i=0; i<SIZE; ++i)
    {
        printf("%i\t", arr2[i]); // *(arr+i)
    }
    puts("\n");
    puts("**************************************************");
    puts("Pointer to array:\n");
    puts("int(*ptr)[5]: ptr is a pointer to array of 5 int.\n");
    puts("int *ptr[5]: ptr is an array of 5 pointers to int.\n");
    puts("step of pointer to array = array size.\n");
    puts("You need to use (**ptr) or (*ptr[i]) to access array elements using pointer to array.\n");

    int (*ptr)[5] = &arr2;//ptr is a pointer to array.
    printf("ptr  = %i\n", ptr);
    printf("*ptr = %i\n", *ptr);//*ptr is a pointer to int
    printf("**ptr = %i\n", **ptr);//**ptr is the first element in the array
    





    puts("**************************************************");
    //gets();
    return 0;
}


void print_array(int *ptr)
{
    char i = 0;
    for(i=0; i<SIZE; ++i)
    {
        printf("%i, ", ptr[i]); // *(ptr+i)
    }
    puts("\b\b)\n"); //new line
}