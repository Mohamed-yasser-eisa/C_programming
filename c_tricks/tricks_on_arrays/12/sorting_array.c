#include <stdio.h>
#include <stdlib.h>

void array_sort(int *ptr, int size);


int main()
{
    puts("**************************************************");
    int array[5];
    int i=0;
    puts("Please enter 5 array elements to sort them in ascending order:\n");
    for(i=0; i<5; ++i)
    {
        scanf("%i", &array[i]);
    }
    printf("Array elements: ( ");
    for(i=0; i<5; ++i)
    {
        printf("%i, ", *(array + i) );
    }
    puts("\b\b )\n\n");

    array_sort(array, (sizeof(array)/sizeof(int)) );
    
    printf("Sorted array: ( ");
    for(i=0; i<5; ++i)
    {
        printf("%i, ", *(array + i) );
    }
    puts("\b\b )");
    
    //printf("Maximum number = %i\n", array_max(array, (sizeof(array)/sizeof(int)) ) );



    puts("**************************************************");
    fflush(stdin);
    gets((char*)array);
    return 0;
}


void array_sort(int *ptr, int size)
{
    int min = 0;
    int i = 0;
    int j=0;
    int temp_array[size];
    
    for(i=0; i<size; ++i)
    {
        for(j=0; j<size; ++j)
        {
            min = ptr[i];
            if(ptr[j] < min )
            {
                min = ptr[i];
            }
        }
        ++j;
        temp_array[i] = min;
    }
    for(i=0; i<size; ++i)
    {
        ptr[i] = temp_array[i];
    }
}
