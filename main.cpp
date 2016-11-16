#include "Included.hpp"
#include "Sort.hpp"

typedef struct Big_O Big_O;

struct Big_O{
    double random;
    double sorted;
    double reversed;
    double total_time;
    double avg_time;
};

void print_array(int array[]);//prints all the values in an array
int size_array(int array[]);//returns the size of an array
void rev_array(int array[], int last_index);//reverses the array
int* create_rand_array(int size, int min, int max); //creates a random array with values between "min" 
                                                    //and "max"(inclusive), of size "size"
void test_quicksort(Sort Test, int trials);
void test_bubble(Sort Test, int trials);

bool writeFile(std::string Output, int Input[], double Output1[], double Output2[], int Num_Entries);

int size_of_array_q[] = {10, 20, 30, 40, 50, 60, 70, 80, 100, 125, 150, 175, 200, 250, 300, 400, 500, 750, 1000, 2000, 3000, 4000, 5000, 7500, 10000, 20000, int(NULL)};
int size_of_array_b[] = {10, 20, 30, 40, 50, 60, 70, 80, 100, 125, 150, 175, 200, 250, 300, 400, 500, 750, 1000, int(NULL)};
const int min_array = 1;
const int max_array = 100000;
const int num_trials = 10;
const std::string RAND_FILE_q = "rand_q.csv";
const std::string SORT_FILE_q = "sort_q.csv";
const std::string REV_FILE_q = "rev_q.csv";
const std::string RAND_FILE_b = "rand_b.csv";
const std::string SORT_FILE_b = "sort_b.csv";
const std::string REV_FILE_b = "rev_b.csv";

int main()
{
    Sort Test_Sort;
    printf("\n------Initialising Array------\n");
    int* quick_test_array = create_rand_array(size_of_array_q[6], min_array, max_array);
    print_array(quick_test_array);
    printf("size of quick_test_array is: %d\n", size_array(quick_test_array));
    printf("------Finished Initialising Array------\n");
    printf("------Performing Random QUICKSORT------\n");
    Test_Sort.QUICKSORT(quick_test_array, 0, size_array(quick_test_array)-1);
    print_array(quick_test_array);
    Test_Sort.print();
    printf("------Finished Random QUICKSORT------\n");
    printf("------Performing Sorted QUICKSORT------\n");
    Test_Sort.QUICKSORT(quick_test_array, 0, size_array(quick_test_array)-1);
    print_array(quick_test_array);
    Test_Sort.print();
    printf("------Finished Sorted QUICKSORT------\n");
    printf("------Reversing Quick Array------\n");
    rev_array(quick_test_array, size_array(quick_test_array)-1);
    print_array(quick_test_array);
    printf("------Finished Reversing Array------\n");
    printf("------Performing Reversed QUICKSORT------\n");
    Test_Sort.QUICKSORT(quick_test_array, 0, size_array(quick_test_array)-1);
    print_array(quick_test_array);
    Test_Sort.print();
    printf("------Finished Reversed QUICKSORT------\n\n");

    printf("\n------Initialising Array------\n");
    int* bubble_test_array = create_rand_array(size_of_array_b[6], min_array, max_array);
    print_array(bubble_test_array);
    printf("size of bubble_test_array is: %d\n", size_array(bubble_test_array));
    printf("------Finished Initialising Array------\n");
    printf("------Performing Random BubbleSort------\n");
    Test_Sort.BUBBLESORT(bubble_test_array, 0, size_array(bubble_test_array)-1);
    print_array(bubble_test_array);
    Test_Sort.print();
    printf("------Finished Random BUBBLESORT------\n");
    printf("------Performing Sorted BUBBLESORT------\n");
    Test_Sort.BUBBLESORT(bubble_test_array, 0, size_array(bubble_test_array)-1);
    print_array(bubble_test_array);
    Test_Sort.print();
    printf("------Finished Sorted BUBBLESORT------\n");
    printf("------Reversing Bubble Array------\n");
    rev_array(bubble_test_array, size_array(bubble_test_array)-1);
    print_array(bubble_test_array);
    printf("------Finished Reversing Array------\n");
    printf("------Performing Reversed BUBBLESORT------\n");
    Test_Sort.BUBBLESORT(bubble_test_array, 0, size_array(bubble_test_array)-1);
    print_array(bubble_test_array);
    Test_Sort.print();
    printf("------Finished Reversed BUBBLESORT------\n\n");

    printf("------Performing QUICKSORT test------\n");
    //Big_O* quick = new Big_O;
    test_quicksort(Test_Sort, num_trials);
    //printf("Quicksort results:\nRandom: %f\nSorted: %f\nReverese: %f\nTotal Time: %f\nAverage Time: %f\n", quick->random, quick->sorted, quick->reversed, quick->total_time, quick->avg_time);
    printf("------Finished QUICKSORT test------\n");
    printf("------Performing BUBBLESORT test------\n");
    //Big_O* bub = new Big_O;
    test_bubble(Test_Sort, num_trials);
    //printf("BUBBLESORT results:\nRandom: %f\nSorted: %f\nReverese: %f\nTotal Time: %f\nAverage Time: %f\n", bub->random, bub->sorted, bub->reversed, bub->total_time, bub->avg_time);
    printf("------Finished BUBBLESORT test------\n\n");

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
    int i = 0;
    while(array[i]){
        i++;
    }
    return i;
}

void rev_array(int array[], int last_index){
    int temp = 0;

    for(int i = 0; i < ((last_index - (last_index%2))/2); i++){
        temp = array[i];
        array[i] = array[last_index - i];
        array[last_index - i] = temp;
    }
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

void test_quicksort(Sort Test, int trials){
    std::clock_t start;

    double rand, sorted, reversed;
    double rand_duration, sorted_duration, reversed_duration;
    
    double rand_a[size_array(size_of_array_q)];
    double sorted_a[size_array(size_of_array_q)];
    double reversed_a[size_array(size_of_array_q)];

    double rand_t[size_array(size_of_array_q)];
    double sorted_t[size_array(size_of_array_q)];
    double reversed_t[size_array(size_of_array_q)];

    for(int i = 0; i<size_array(size_of_array_q); i=i+1){
        printf("Starting test array of size: %d\n", size_of_array_q[i]);
        rand_duration = sorted_duration = reversed_duration = 0;
        rand = sorted = reversed = 0;
        for(int j = 0; j< trials; j = j+1)
        {
            int* quick_test_array = create_rand_array(size_of_array_q[i], min_array, max_array);
            
            start = std::clock();
            Test.QUICKSORT(quick_test_array, 0, size_array(quick_test_array)-1);
            rand += Test.return_probes();
            rand_duration += ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

            start = std::clock();
            Test.QUICKSORT(quick_test_array, 0, size_array(quick_test_array)-1);
            sorted += Test.return_probes();
            sorted_duration += ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

            rev_array(quick_test_array, size_array(quick_test_array)-1);
            start = std::clock();
            Test.QUICKSORT(quick_test_array, 0, size_array(quick_test_array)-1);
            reversed += Test.return_probes();
            reversed_duration += ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

            delete[] quick_test_array;
        }
        rand_a[i] = rand/trials;
        sorted_a[i] = sorted/trials;
        reversed_a[i] = reversed/trials;

        rand_t[i] = rand_duration/trials;
        sorted_t[i] = sorted_duration/trials;
        reversed_t[i] = reversed_duration/trials;
    }
    
    writeFile(RAND_FILE_q, size_of_array_q, rand_a, rand_t, size_array(size_of_array_q));
    writeFile(SORT_FILE_q, size_of_array_q, sorted_a, sorted_t, size_array(size_of_array_q));
    writeFile(REV_FILE_q, size_of_array_q, reversed_a, reversed_t, size_array(size_of_array_q));
}

void test_bubble(Sort Test, int trials){
    std::clock_t start;

    double rand, sorted, reversed;
    double rand_duration, sorted_duration, reversed_duration;
    
    double rand_a[size_array(size_of_array_b)];
    double sorted_a[size_array(size_of_array_b)];
    double reversed_a[size_array(size_of_array_b)];

    double rand_t[size_array(size_of_array_b)];
    double sorted_t[size_array(size_of_array_b)];
    double reversed_t[size_array(size_of_array_b)];

    for(int i = 0; i<size_array(size_of_array_b); i=i+1){
        printf("Starting test array of size: %d\n", size_of_array_b[i]);
        rand_duration = sorted_duration = reversed_duration = 0;
        rand = sorted = reversed = 0;
        for(int j = 0; j< trials; j = j+1)
        {
            int* bubble_test_array = create_rand_array(size_of_array_b[i], min_array, max_array);
            
            start = std::clock();
            Test.BUBBLESORT(bubble_test_array, 0, size_array(bubble_test_array)-1);
            rand += Test.return_probes();
            rand_duration += ( std::clock() - start ) / (double) CLOCKS_PER_SEC;


            start = std::clock();
            Test.BUBBLESORT(bubble_test_array, 0, size_array(bubble_test_array)-1);
            sorted += Test.return_probes();
            sorted_duration += ( std::clock() - start ) / (double) CLOCKS_PER_SEC;


            rev_array(bubble_test_array, size_array(bubble_test_array)-1);
            start = std::clock();
            Test.BUBBLESORT(bubble_test_array, 0, size_array(bubble_test_array)-1);
            reversed += Test.return_probes();
            reversed_duration += ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

            delete[] bubble_test_array;
        }
        rand_a[i] = rand/trials;
        sorted_a[i] = sorted/trials;
        reversed_a[i] = reversed/trials;

        rand_t[i] = rand_duration/trials;
        sorted_t[i] = sorted_duration/trials;
        reversed_t[i] = reversed_duration/trials;
    }
    writeFile(RAND_FILE_b, size_of_array_b, rand_a, rand_t, size_array(size_of_array_b));
    writeFile(SORT_FILE_b, size_of_array_b, sorted_a, sorted_t, size_array(size_of_array_b));
    writeFile(REV_FILE_b, size_of_array_b, reversed_a, reversed_t, size_array(size_of_array_b));
}

bool writeFile(std::string Output, int Input[], double Output1[], double Output2[], int Num_Entries)
{
    std::ofstream *Out = new std::ofstream;
    Out->open(Output);
    if (Out->fail()) //if fail outout error
    {
        std::cout << "Could not open Output file." << std::endl;
        Out->close();
        return false;
    }
    else
    {
        std::cout << "Output file opened successfully." << std::endl;
        for (int i = 0; i < Num_Entries; i++)
        {
            *Out << Input[i] << ", " << Output1[i] << ", " << Output2[i] << std::endl;
        }
        *Out << std::endl;
        Out->close();
        return true;
    }
}