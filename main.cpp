/* 
 * File:   main.cpp
 * Author: Nenad Erceg
 *
 * Created on January 21, 2014, 2:39 AM
 */
#include <cstdlib>
#include <iostream>
#include "utill.h"
#include <chrono>
#include <utility>

#define MAX 10000
#define HIGH 878
#define LOW 47
#define VALUE 12

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

typedef std::chrono::high_resolution_clock::time_point TimeVar;


using namespace std;

/*
 *
 * Driver program to test sorting algorithms 
 */
int main(int argc, char** argv) {
    
    int size = MAX;
    int a[size];
    
    srand(time(NULL));

    fillArray(a, size, LOW, HIGH);
    displayArray(a, size);

    cout << endl << endl << "**********-------SORTED ARRAY--------************" << endl;

    // measure time
    TimeVar t1=timeNow();
    
    //insertionSort(a, size);
    //insertionSort(a, 0, size -1);
    //selectionSort(a, size);
    //quickSort2(a, 0, size - 1);
    //quickSort(a, 0, size - 1);
    //quickSort(a, 0, size - 1); /////////////////////////////////
    //quicksort(a, size);
    //iterativeQuickSort(a, size);
    shellSort(a, size);
    
    double long e = duration(timeNow()-t1);

    displayArray(a, size);
    
    cout << endl << endl;

    if (isSorted(a, size)) {
        cout << "**************------SUCCESS--------**************\n\n";
    } else
        cout << "***************------ERORR--------***************\n\n";
    
    cout << "Execution time of sorting algorithm: " << e << " ns" << endl;

    return 0;
}
