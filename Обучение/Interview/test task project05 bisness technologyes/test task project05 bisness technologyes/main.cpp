//
//  main.cpp
//  test task project05 bisness technologyes
//
//  Created by Владислав Легков on 07/07/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <cmath>
/**
 Buble array sort
 */
void sort (int *array, const int start, const int end){
    if (start > end) {
        std::cout << "FATAL ERROR. Start is bigger than end.\n\n";
    } else {
        for (int i = start; i < end-1; i++){
            for (int j = i; j < end; j++) {
                if (array[i] > array [j]){
                    std::swap (array[i], array[j]);
                }
            }
        }
    }
    
}

/**
 Print array to the command line
 */

void printArray (int* array, size_t length){
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << "\t";
    }
    std::cout << "\n";
}

/**
 Main method
 */

int roundHalfDown(const int fistNumber, const int secondNumber){
    return floor(fistNumber+secondNumber/2);
}

/*
 Method to merge information by two arrays
 */
void mergeArray (int* array, size_t start, size_t center, size_t end){
    
    /*
     Variables and buffer array to merge data
     */
    
    int* arrayResult = new int [end];
    size_t iteratorFirst = start - 1;
    size_t iteratorSecond = center;
    size_t i = start - 1;
    
    /*
     Compare elements by part of arrays
     */
    
    while (iteratorFirst < center && iteratorSecond < end) {
        if (array[iteratorFirst] < array[iteratorSecond]){
            arrayResult[i] = array[iteratorFirst];
            iteratorFirst++;
        } else{
            arrayResult[i] = array[iteratorSecond];
            iteratorSecond++;
        }
        i++;
    }
    
    /*
     If elements of array parts are over
     */

    while (iteratorSecond < end) {
        arrayResult[i] = array[iteratorSecond];
        iteratorSecond++;
        i++;
    }
    while (iteratorFirst < center) {
        arrayResult[i] = array[iteratorFirst];
        iteratorFirst++;
        i++;
    }
    
    /*
     rewrite elements from buffer to main array
     */
    
    for (size_t j = start - 1; j < i; j++){
        array[j] = arrayResult[j];
    }
}

/*
 Merge sort method
 */

void mergeSort (int* array, size_t start, size_t end){
    if (start < end) {
        size_t q = start + (end-start) / 2;
        mergeSort(array, start, q);
        mergeSort(array, q + 1, end);
        mergeArray(array, start, q, end);
    }
}

/*
 Example of calling method like in the task
 
 mergeSort(array, 1, length);
 
 start sort element is 1
 last sort element is array length
 */


int main(int argc, const char * argv[]) {
    const int length = 1000;
    int* array = new int [length];
    for (int i = 0; i < length; i++){
        array[i] = rand() % 100000+1;
      //  array[i] = length - i;
    }
    
    int* buffer = new int [length];
    for (size_t i = 0; i < length; i++){
        buffer[i] = array[i];
    }
    std::cout << "start array ";
    printArray(array, length);
    mergeSort(array, 1, length);
    std::cout << "end's array ";
    printArray(array, length);

    delete [] array;
    return 0;
}
