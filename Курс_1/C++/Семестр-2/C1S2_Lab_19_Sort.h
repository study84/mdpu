#pragma once

#include <vector>

using namespace std;



void bubbleSort(vector<int>& arr); // Bubble Sort - пузырьковая 
void insertionSort(vector<int>& arr); // Insertion Sort - вставками
void selectionSort(vector<int>& arr); // Selection Sort - выбором

void quickSort(vector<int>& arr, int low, int high); // Quick Sort - быстроя сортировка
void mergeSort(vector<int>& arr, int const begin, int const end); // Merge Sort - сортировка слиянием

void countingSort(vector<int>& arr); // Counting Sort - сортировка подсчетом
void radixSort(vector<int>& arr); // Radix Sort - цифровая сортировка
