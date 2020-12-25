#include <stdio.h>
#include "isort.h"

//The function gets a pointer to the array and a number i.
//The function moves the follow i numbers one place to the right.
void shift_element(int* arr, int i){
    int j;
    for(j = i; j > 0; j--){
        *(arr+j) = *(arr+(j-1));
    }
}

//The function gets array with size of len, and sort it by using insertion sort algo
void insertion_sort(int* arr, int len){
    int i, j;
    for(i = 0; i < len; i++){
        int min, minIndex;
            min = *(arr+i);
        for(j = i; j < len-1; j++){
            if(min > *(arr+j+1)){
                min = *(arr+j+1);
                minIndex = j+1;
            }
        }
        if(min != *(arr+i)){
            shift_element(arr+i, minIndex-i);
            *(arr+i) = min;
        }  
    }       
}