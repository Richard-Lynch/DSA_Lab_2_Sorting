#include "Sort.hpp"

Sort::Sort(){
    probes = 0;//initialise probes to 0
}

int Sort::print(){
    printf("Sort required %d probes\n", probes);//print the number of probes
    int temp = probes;
    probes = 0;//reset probe counter
    return temp;
}

int Sort::return_probes(){
    int temp = probes;
    probes = 0;//reset probe counter
    return temp;
}

void Sort::QUICKSORT(int* Array, int first, int last){
    if (first < last){// this will ensure we havnt "crossed over" our index values
        
        //calls the partition function, which will sort the list such that; 
        //all values on the left of the pivot will be less than the pivot, 
        //all values on the right of the pivot will be greater than the pivot.
        //the pivot is the LAST ITEM IN THE CURRENT ARRAY(the array between the two index's we are checking)
        int pivot = PARTITION(Array, first, last);

        //quicksort is then called recursivly on the "first array" ie the index's on the left of the pivot in the current array
        //quicksort is then called recursivly on the "second array" ie the index's on the right of the pivot in the current array        
        lc
    }
}

 int Sort::PARTITION(int* Array, int first, int last){
    //use the middle value as the pivot. this means that for a sorted and reveresed arrays, less probes are needed
    std::swap(Array[last], Array[int((last-first)/2)]);

    int last_value = Array[last];//the last value, which will be the pivot VALUE is polled
    int prev = first - 1; // the "prev" index is set to one less than the first index
     
    //starting at the first index of the current array, 
    //until the second last, add one to the curr index on each loop
    for(int curr = first; curr<last; curr++){
        //if the value at the "curr" index is less than the last value or "pivot value"
        //move the "prev" index forward and then swap the previous index with the "curr" index
        //this effectivly puts all values less than the pivot value in or before the "prev" index
        if(Array[curr] <= last_value){
            prev++;
            std::swap(Array[prev], Array[curr]);
        }
        probes++;//increment the number of probes
    }
    //when the end of the array is reached; 
    //swap the pivot value with the value one index to the right of the "prev" index
    //remember that all value in or before the "prev" index were less than the pivot value
    //this means that now, all values on the left of "prev+1"(the pivot index) are less than the pivot value
    //and all values on the right of "prev+1"(the pivot index) are greater than the pivot value
    std::swap(Array[prev + 1], Array[last]);
    return prev + 1; // return "prev+1" the pivot index
}

void Sort::BUBBLESORT(int* Array, int first, int last){
    bool sorted = false;//start with the list unsorted
    while(sorted == false){//while the list is still unsorted
        sorted = true;//set to true temporarily
        for(int i = first; i<last; i++){//for each value in the array
            if(Array[i+1] < Array[i]){//if the next value is less than the current value, 
                std::swap(Array[i+1], Array[i]);//swap these values,
                sorted = false;//and set sorted back to false as we've found an item in the list which is unsorted
            }
            probes++;//add one to probes every time we compare two values
        }
    }
}