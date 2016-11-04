#include "Included.hpp"
#include "Sort.hpp"
#include "QuickSort.hpp"

void print_array(int array[]);
int size_array(int array[]);

int main()
{
    int test_array[] = {2, 3, 5, 6, 1, 24, 7, 12, 4, int(NULL)};
    print_array(test_array);
    printf("size of array is: %d\n", size_array(test_array));
    QuickSort first_sort;
    first_sort.QUICKSORT(test_array, 0, size_array(test_array)-1);
    print_array(test_array);
    

    return 0;
}

void print_array(int array[]){
    int i = 0;
    while(array[i+1]){
        printf("%d, ", array[i]);
        i++;
    }
    printf("%d \n", array[i]);
}

int size_array(int array[]){
    int i = 1;
    while(array[i]){
        i++;
    }
    return i;
}