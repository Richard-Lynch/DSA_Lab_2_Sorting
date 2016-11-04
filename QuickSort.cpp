#include "QuickSort.hpp"


void QuickSort::QUICKSORT(int* Array, int first, int last){
    if (first < last){
        int pivot = PARTITION(Array, first, last);
        QUICKSORT(Array, first, pivot-1);
        QUICKSORT(Array, pivot+1, last);
    }
}

 int QuickSort::PARTITION(int* Array, int first, int last){
     int last_value = Array[last];
     int prev = first - 1;

     for(int curr = first; curr<last; curr++){
         if(Array[curr] <= last_value){
             prev++;
             std::swap(Array[prev], Array[curr]);
         }
     }
     std::swap(Array[prev + 1], Array[last]);
     return prev + 1;
 }