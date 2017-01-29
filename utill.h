/* 
 * File:   utill.h
 * Author: Nenad Erceg
 *
 * Created on January 25, 2017, 7:01 PM
 */

#ifndef UTILL_H
#define	UTILL_H


void selectionSort(int a[], int size);

void insertionSort(int a[], int size);

void insertionSort(int a[], int left, int right);

void shellSort(int a[], int size);

void quickSort(int a[], int left, int right);

void quickSort1(int a[], int left, int right);

void quickSort2(int a[], int left, int right);

void quickSort3(int arr[], int left, int right);

int choosePivot(int a[], int left, int right);

int choosePivot1(int a[], int left, int right);

int partition3(int arr[], int left, int right);

void displayArray(int a[], int size);

void fillArray(int a[], int size, int low, int high);

void fillArray(int a[], int size, int value);

int randInt(int min, int max);

bool isSorted(int a[], int size);

void iterativeQuickSort(int a[], int last);

void iterativeQuickSort2(int *arr, int elements);


#endif	/* UTILL_H */

