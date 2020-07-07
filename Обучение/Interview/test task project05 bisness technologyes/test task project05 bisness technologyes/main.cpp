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

void printArray (int* array, const int length){
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

void mergeArray (int* array, const int start, const int center, const int end){
    
/*
    int lengthFisrtArray = center;
    int lengthSecondArray = end - center;
    int* firstArray = new int [lengthFisrtArray];
    int* secondArray = new int [lengthSecondArray];
    std::cout << lengthFisrtArray << "_____" << lengthSecondArray << "\n";
    for (int i = start; i < center; i++ ){
        firstArray[i] = array[i];
    }
    int j = 0;
    for (int i = center; i < end;  i++){
        secondArray[j] = array[i];
        j++;
    }
    printArray(firstArray, lengthFisrtArray);
    printArray(secondArray, lengthSecondArray);
    
    int newCenter = NULL;
    
    if (end % 2 != 0) {
        newCenter = center+1;
    } else {
        newCenter = center;
    }
    
    for (int i = 0; i < newCenter; i++){
        array[i] = secondArray[i];
    }
    j=0;
    for (int i = newCenter; i < end; i++){
        array[i] = firstArray[j];
        j++;
    } */
    
    if (start - center == 1) {
        std::swap (array[start],array[center]);
    }
    if (center+1 - end == 1) {
        std::swap (array[center+1],array[end]);
    }
}

void finalSort (int* array, const int start, const int end){
    if (start < end) {
        int q = roundHalfDown(start, end);
        finalSort(array, start, q);
        finalSort(array, q+1, end);
        mergeArray(array, start, q, end);
    }
    
    std::cout << "-----------\n";
    printArray(array, end);
}

int main(int argc, const char * argv[]) {
    const int length = 4;
    int* array = new int [length];
    for (int i = 0; i < length; i++){
        array[i] = rand()%100+1;
    }
    printArray(array, length);
    //sort(array, 1, length);
    //printArray(array, length);
    //std::cout << roundHalfDown(0, length);
    
   // mergeArray(array, 0, roundHalfDown(0, length), length);
   // printArray(array, length);
    finalSort(array, 0, length);
    printArray(array, length);
    delete [] array;
    return 0;
}
