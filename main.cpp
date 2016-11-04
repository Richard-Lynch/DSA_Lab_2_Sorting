#include "Included.hpp"
#include "Sort.hpp"

void print_array(int array[]);//prints all the values in an array
int size_array(int array[]);//returns the size of an array
int* create_rand_array(int size, int min, int max);//creates a random array with values between "min" and "max", of size "size"

const int size_of_array = 10;
const int min_array = 1;
const int max_array = 10;

int main()
{
    Sort Test_Sort;
    printf("\n------Initialising Array------\n");
    int* quick_test_array = create_rand_array(size_of_array, min_array, max_array);
    print_array(quick_test_array);
    printf("size of quick_test_array is: %d\n", size_array(quick_test_array));
    printf("------Finished Initialising Array------\n");
    printf("------Performing First QUICKSORT------\n");
    Test_Sort.QUICKSORT(quick_test_array, 0, size_array(quick_test_array)-1);
    print_array(quick_test_array);
    Test_Sort.print();
    printf("------Finished First QUICKSORT------\n");
    printf("------Performing Second QUICKSORT------\n");
    Test_Sort.QUICKSORT(quick_test_array, 0, size_array(quick_test_array)-1);
    print_array(quick_test_array);
    Test_Sort.print();
    printf("------Finished Second QUICKSORT------\n\n");

    printf("\n------Initialising Array------\n");
    int* bubble_test_array = create_rand_array(size_of_array, min_array, max_array);
    print_array(bubble_test_array);
    printf("size of bubble_test_array is: %d\n", size_array(bubble_test_array));
    printf("------Finished Initialising Array------\n");
    printf("------Performing First BubbleSort------\n");
    Test_Sort.BUBBLESORT(bubble_test_array, 0, size_array(bubble_test_array)-1);
    print_array(bubble_test_array);
    Test_Sort.print();
    printf("------Finished First BUBBLESORT------\n");
    printf("------Performing Second BUBBLESORT------\n");
    Test_Sort.BUBBLESORT(bubble_test_array, 0, size_array(bubble_test_array)-1);
    print_array(bubble_test_array);
    Test_Sort.print();
    printf("------Finished Second BUBBLESORT------\n\n");



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

int* create_rand_array(int size, int min, int max){
    srand (time(NULL));
    int* array = new int[size+1];
    for(int i = 0; i<size; i++){
        array[i] =  (rand()%(max)) + min;
    }
    array[size] = int(NULL);
    return array;
}