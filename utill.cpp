#define NDEBUG

#include "utill.h"

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <cassert>
#include <stack>
#include <cmath>

using namespace std;

void selectionSort(int a[], int size) {
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            swap(a[i], a[minIndex]);
        }
    }
}

void insertionSort(int a[], int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = a[i];
        j = i;
        while (j > 0 && a[j - 1] > key) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = key;
    }
}

void insertionSort(int a[], int left, int right) {
    int key, j;
    for (int i = left + 1; i <= right; i++) {
        key = a[i];
        j = i;
        while (j > 0 && a[j - 1] > key) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = key;
    }
}

void shellSort(int a[], int size) {

    int key, j;
    int t = static_cast<int> (log2(size/2.0 + 1));
    
    for (int gap = pow(2, t) - 1; gap >= 1; gap = pow(2, t) - 1) {
        for (int i = gap; i < size; i++) {
            key = a[i];
            j = i;
            while (j >= gap  && a[j - gap] > key) {
                a[j] = a[j - gap];
                j-= gap;
            }
            a[j] = key;
        }
        t--;
    }
}

void iterativeQuickSort(int a[], int size) {
    stack<int> s;
    int left, right;
    //s.push(0, last);
    s.push(size - 1);
    s.push(0);

    while (!s.empty()) {
        //s.pop(left, right);
        left = s.top();
        s.pop();
        right = s.top();
        s.pop();

        while (left + 1 < right /* or right - MINSIZE */) {

            int pivot = choosePivot(a, left, right);
            // partition step 
            int i = left;
            int j = right - 1;
            while (true) {
                while (a[++i] < pivot) {
                }
                while (pivot < a[--j]) {
                }

                if (i < j) {
                    swap(a[i], a[j]);
                } else
                    break;
            }
            // move pivot into position 
            swap(a[i], a[right]);

            if ((right - i) > (j - left)) {
                if (right > i) {
                    //s.push(i, right);
                    s.push(right);
                    s.push(i);
                    right = j;
                }
            } else {
                //assert(j <= left);
                if (j > left) {
                    //s.push(left, j);
                    s.push(j);
                    s.push(left);
                    left = i;
                }
            }
        }
        insertionSort(a, left, right);
        // could do the insertion sort here if right-left < MINSIZE
    }
}

int choosePivot(int a[], int left, int right) {

    int mid = a[(left + right) / 2]; //randInt(left, right);
    if (a[left] > a[mid])
        swap(a[left], a[mid]);
    if (a[left] > a[right])
        swap(a[left], a[right]);
    if (a[mid] < a[right])
        swap(a[mid], a[right]);

    swap(a[mid], a[right - 1]);

    assert(a[left] <= a[right]);
    assert(a[right - 1] >= a[right]);

    return a[right];
}

/* left  --> Starting index,  right  --> Ending index */
void quickSort(int a[], int left, int right) {

    if (left + 2 <= right) {
        // median-of-3 pivot selection
        // pick random value from array and put pivot into a[right]
        int pivot = choosePivot(a, left, right); // a[left] <=  pivot = a[right] <= a[right - 1]

        // now partition
        int i = left;
        int j = right - 1;

        while (true) {
            while (a[++i] < pivot); // advance i 
            while (pivot < a[--j]); // advance j  

            assert(a[i] >= pivot && a[j] <= pivot);
            // a[i] >= pivot and a[j] <= pivot
            if (i < j)
                swap(a[i], a[j]);
            else
                break;
        }
        assert(j <= i && a[i] >= pivot && a[j] <= pivot);
        assert(i - j <= 1 && i - j >= 0);
        // now j <= i and a[i] >= pivot and a[j] <= pivot
        // so we can swap the pivot with a[i]
        swap(a[i], a[right]);

        // Now the pivot is between the two sets and in a[i]
        // quickSort the left set:
        quickSort(a, left, i - 1);

        // quickSort the right set:
        quickSort(a, i + 1, right);
    }
    else {
        //could do insertionSort(a, left, right);
        if (a[left] > a[right])
            swap(a[left], a[right]);
    }
}

int choosePivot1(int a[], int left, int right) {
    int mid = (left + right) / 2;
    swap(a[mid], a[right]);
    return a[right];
}

/* left  --> Starting index,  right  --> Ending index */
void quickSort1(int a[], int left, int right) {

    if (left < right) {
        //median-of-3 pivot selection
        // pick random value from array and put it (pivot) into a[right]
        int pivot = choosePivot1(a, left, right);
        // a[left] <=  pivot = a[right] <= a[right - 1]

        // now partition
        int i = left;
        int j = right - 1;

        while (true) {
            while (i <= j && a[i] <= pivot) {
                i++;
            } // advance i ** i <= j && 
            while (i <= j && pivot <= a[j]) {
                j--;
            } // advance j ** i <= j && 

            //assert(a[i] > pivot && a[j] < pivot);
            // A[i] > pivot and A[j] < pivot
            if (i < j) {
                swap(a[i++], a[j--]);
            } else {
                break;
            }
        }

        assert(i - j <= 1 && i - j >= 0);
        //assert(j <= i && a[i] > pivot && a[j] < pivot);
        // now j <= i and a[i] >= pivot and a[j] <= pivot
        // so we can swap the pivot with a[i]
        swap(a[i], a[right]);
        // Now the pivot is between the two sets and in a[i]
        // quickSort the left set:
        quickSort1(a, left, i - 1);
        // quickSort the right set:
        quickSort1(a, i + 1, right);
    }
}

void quickSort2(int a[], int left, int right) {

    int i = left, j = right;

    int pivot = a[randInt(left, right)];

    /* partition */
    while (true) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j) {
            swap(a[i++], a[j--]);
        } else break;
    }

    assert((i - j) <= 2 && (i - j) >= 0);
    /* recursion */
    if (left < j) // or i -1 instead of j 
        quickSort2(a, left, j);
    if (i < right)
        quickSort2(a, i, right);
}

int partition3(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return i;
}

void quickSort3(int arr[], int left, int right) {
    int index = partition3(arr, left, right);
    if (left < index - 1)
        quickSort3(arr, left, index - 1);
    if (index < right)
        quickSort3(arr, index, right);
}

void displayArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        if (i % 10 == 0)
            cout << endl;
        cout << setw(4) << a[i] << " ";
    }
}

void fillArray(int a[], int size, int low, int high) {

    for (int i = 0; i < size; i++)
        a[i] = randInt(low, high);
}

void fillArray(int a[], int size, int value) {
    for (int i = 0; i < size; i++)
        a[i] = value;
}

int randInt(int min, int max) {

    int randomNum = rand() % (max - min - 1) + min + 1;
    assert(randomNum > min && randomNum < max);
    return randomNum;
}

bool isSorted(int a[], int size) {
    bool sorted = true;
    for (int i = 1; i < size; i++) {
        if (a[i - 1] > a[i]) {
            cout << "ERROR: " << a[i - 1] << endl;
            sorted = false;
        }
    }
    return sorted;
}

/////////
////////

// An iterative implementation of quick sort

void iterativeQuickSort2(int *a, int size) {

#define  MAX_LEVELS  300

    int pivot, beg[MAX_LEVELS], end[MAX_LEVELS], i = 0, left, right;

    beg[0] = 0;
    end[0] = size;

    while (i >= 0) {

        left = beg[i];
        right = end[i] - 1;

        if (left < right) {
            pivot = a[left];

            while (left < right) {
                while (a[right] >= pivot && left < right)
                    right--;
                if (left < right)
                    a[left++] = a[right];
                while (a[left] <= pivot && left < right)
                    left++;
                if (left < right)
                    a[right--] = a[left];
            }
            a[left] = pivot;
            beg[i + 1] = left + 1;
            end[i + 1] = end[i];
            end[i++] = left;

            if (end[i] - beg[i] > end[i - 1] - beg[i - 1]) {
                swap(beg[i], beg[i - 1]);
                swap(end[i], end[i - 1]);
            }
        } else {
            i--;
        }
    }
}

