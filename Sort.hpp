#include "Included.hpp"

class Sort{
    private:
    int probes;//stores the number of probes required for a sort, used be "print()"
    
    public:
    //Quick
    void QUICKSORT(int* Array, int first, int last);//quicksort function
    int PARTITION(int* Array, int first, int last);//partition function called by quick sort - finds the pivot and performs sort

    //bubble
    void BUBBLESORT(int* Array, int first, int last);//bubblesort functuons

    //general
    void print();//prints the number of probes required and clears probes

    Sort();//initialises probes to 0
};