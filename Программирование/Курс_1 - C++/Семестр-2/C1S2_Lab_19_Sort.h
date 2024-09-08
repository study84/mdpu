#pragma once

#include <vector>

using namespace std;



void bubbleSort(vector<int>& arr); // Bubble Sort - ����������� 
void insertionSort(vector<int>& arr); // Insertion Sort - ���������
void selectionSort(vector<int>& arr); // Selection Sort - �������

void quickSort(vector<int>& arr, int low, int high); // Quick Sort - ������� ����������
void mergeSort(vector<int>& arr, int const begin, int const end); // Merge Sort - ���������� ��������

void countingSort(vector<int>& arr); // Counting Sort - ���������� ���������
void radixSort(vector<int>& arr); // Radix Sort - �������� ����������
