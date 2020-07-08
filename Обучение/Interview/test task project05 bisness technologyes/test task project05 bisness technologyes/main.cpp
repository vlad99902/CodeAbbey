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
    
    
    
    start--;
    center--;
    end--;
    
    /*
     Variables and buffer array to merge data
     */
    int* arrayResult = new int [end];
    size_t iteratorFirst = start;
    size_t iteratorSecond = center + 1;
    size_t i = start;
    
    /*
     Compare elements by part of arrays
     */
    while (iteratorFirst <= center && iteratorSecond <= end) {
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

    while (iteratorSecond <= end) {
        arrayResult[i] = array[iteratorSecond];
        iteratorSecond++;
        i++;
    }
    while (iteratorFirst <= center) {
        arrayResult[i] = array[iteratorFirst];
        iteratorFirst++;
        i++;
    }
    
    /*
     rewrite elements from buffer to main array
     */
    
    for (size_t j = start; j < i; j++){
        array[j] = arrayResult[j];
    }
}



void finalSort (int* array, const int start, const int end){
    if (start < end) {
        int q = start + (end-start) / 2;
        finalSort(array, start, q);
        finalSort(array, q + 1, end);
        mergeArray(array, start, q, end);
    }
}



int main(int argc, const char * argv[]) {
    const int length = 100;
    int* array = new int [length];
    for (int i = 0; i < length; i++){
        array[i] = rand()%1000+1;
       // array[i] = length - i;
    }
    
    int* buffer = new int [length];
    for (size_t i = 0; i < length; i++){
        buffer[i] = array[i];
    }
    std::cout << "start array ";
    printArray(array, length);
    finalSort(array, 1, length);
    std::cout << "end's array ";
    printArray(array, length);

    delete [] array;
    return 0;
}
