#ifndef SORT_H
#define SORT_H

void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void selectionSort(int arr[], int size);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
void merge(int arr[], int l, int m, int r);
int partition(int arr[], int low, int high);
void heapSort(int arr[], int size);
void heapify(int arr[], int size, int i);
void countingSort(int arr[], int size);
void radixSort(int arr[], int size);
void countingSortForRadix(int arr[], int size, int exp);


#endif // SORT_H
