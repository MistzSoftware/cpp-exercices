#include <iostream>
#include <chrono>

#define SIZE_N 1000

using namespace std;

void merge(int* numArray, int lowerB, int mid, int UpperB){
    int sizeLeft = mid - lowerB + 1;
    int sizeRight = UpperB - mid;

    int* leftArray = new int[sizeLeft];
    int* rightArray = new int[sizeRight];

    for (int i = 0; i < sizeLeft; ++i){
        leftArray[i] = numArray[lowerB + i];
    }
    for (int i = 0; i < sizeRight; ++i){
        rightArray[i] = numArray[mid + 1 + i];
    }

    int i = 0, j = 0, k = lowerB;

    while ((i < sizeLeft) && (j < sizeRight)){
        if (leftArray[i] <= rightArray[j]){
            numArray[k] = leftArray[i];
            ++i;
        } else {
            numArray[k] = rightArray[j];
            ++j;
        }
        ++k;
    }
    
    while (i < sizeLeft){
        numArray[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < sizeRight){
        numArray[k] = rightArray[j];
        ++j;
        ++k;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int* numArray, int lowerB, int upperB){

    if (lowerB >= upperB){
        return;
    }

    int mid = lowerB + (upperB - lowerB) / 2;
    mergeSort(numArray, lowerB, mid);
    mergeSort(numArray, mid + 1, upperB);
    merge(numArray, lowerB, mid, upperB);
}

void printArray(int* numArray, int size){
    cout << "Contents: " << endl;
    for (int i = 0; i < size; ++i){
        cout << numArray[i] << " ";
    }
    cout << endl;
}

int main() {

    // int numArray[] = {64, 34, 25, 12, 22, 11, 90};
    // int size = sizeof(numArray)/sizeof(numArray[0]);

    int numArray[SIZE_N];

    srand(time(0));

    for (int i = 0; i < SIZE_N; ++i){
        numArray[i] = rand() % SIZE_N;
    }

    // Start measuring time
    auto start = chrono::high_resolution_clock::now();

    mergeSort(numArray, 0, SIZE_N - 1);
    printArray(numArray, SIZE_N);
  
    // Stop measuring time
    auto stop = chrono::high_resolution_clock::now();

    // Calculate the duration
    chrono::duration<double> duration = stop - start;
    cout << "Execution time: " << duration.count() << " seconds\n";

    return 0;
}