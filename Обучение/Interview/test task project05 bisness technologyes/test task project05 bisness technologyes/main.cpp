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

void mergeArray (int* array, size_t start, size_t center, size_t end){
  //  if (start != 0) start--;
    if (start - end == -1 || start - center == 0 || center - end == 0) return;
    
    std::cout << "\nmerge method called\n\n\t iterator first: " << start << " iterator second: " << center << " end's: " << end << std::endl;
    
    int* arrayResult = new int [end];
    size_t iteratorFirst = start;
    size_t iteratorSecond = center;
    size_t i = start;
    
    printArray(array, end);
    std::cout << "\n\t iterator first: " << iteratorFirst << " iterator second: " << iteratorSecond << std::endl;
    while (iteratorFirst < center && iteratorSecond < end) {
        std::cout << "\ni: "<< i <<" iterator first: " << iteratorFirst << " iterator second: " << iteratorSecond << std::endl;
        if (array[iteratorFirst] <= array[iteratorSecond]){
            arrayResult[i] = array[iteratorFirst];
            iteratorFirst++;
            i++;
        } else{
           // std::cout << "\non, no!\n";
            arrayResult[i] = array[iteratorSecond];
            iteratorSecond++;
            i++;
        }
    }
    std::cout << "\n\t iterator first: " << iteratorFirst << " iterator second: " << iteratorSecond << std::endl;
    // if array's part end's
    if (iteratorFirst != center) {
        while (iteratorSecond != end) {
            arrayResult[i] = array[iteratorSecond];
            iteratorSecond++;
            i++;
        }
    }
    
    if (iteratorSecond == end) {
        while (iteratorFirst != center) {
            arrayResult[i] = array[iteratorFirst];
            iteratorFirst++;
            i++;
        }
    }
    
    std::cout << "\n\t iterator first: " << iteratorFirst << " iterator second: " << iteratorSecond << std::endl;
    
    printArray(arrayResult, end);
    for (size_t i = start; i < end; i++){
        array[i] = arrayResult[i];
    }
        
}

void finalSort (int* array, const int start, const int end){
    if (start < end) {
        int q = start + (end-start) / 2;
        finalSort(array, start, q);
        finalSort(array, q + 1, end);
        std::cout << "merge called: " << start << "  " << q << "  " << end << std::endl;
        mergeArray(array, start, q, end);
    }
    
    std::cout << "\n--------\n";
}

int main(int argc, const char * argv[]) {
    const int length = 10;
    int* array = new int [length];
    for (int i = 0; i < length; i++){
        array[i] = rand()%100+1;
       // array[i] = length - i;
    }
    std::cout << "start array ";
    printArray(array, length);
    //sort(array, 1, length);
    //printArray(array, length);
    //std::cout << roundHalfDown(0, length);
    
    // mergeArray(array, 0, roundHalfDown(0, length), length);
   // printArray(array, length);
    finalSort(array, 0, length);
    std::cout << "end's array ";
    printArray(array, length);
    delete [] array;
    return 0;
}
