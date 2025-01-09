#include <cstdlib>
#include <iostream>
#include <chrono>

#define SIZE_N 4000

using namespace std;

int _OP_COUNT = 0;
int _COMP_COUNT = 0;

void insertionSort(int* numArray, int size){
    for (int i = 0; i < size - 2; ++i){
        int j = i + 1;
        ++_COMP_COUNT;
        while ((j > 0) && numArray[j-1] > numArray[j]){
            ++_OP_COUNT;
            int temp = numArray[j - 1];
            numArray[j - 1] = numArray[j];
            numArray[j] = temp;
            j = j - 1;
        }
    }
}

void printArray(int* numArray, int size){
    cout << "Contents: " << endl;
    for (int i = 0; i < size; ++i){
        cout << numArray[i] << " ";
    }
    cout << endl;
}

int main() {
    int numArray[SIZE_N];

    srand(time(0));

    for (int i = 0; i < SIZE_N; ++i){
        numArray[i] = rand() % SIZE_N;
    }

    // Start measuring time
    auto start = chrono::high_resolution_clock::now();

    insertionSort(numArray, SIZE_N);
    printArray(numArray, SIZE_N);
    cout << "Number of operations: " << _OP_COUNT << endl;
    cout << "Number of comparisons: " << _COMP_COUNT << endl;

    // Stop measuring time
    auto stop = chrono::high_resolution_clock::now();

    // Calculate the duration
    chrono::duration<double> duration = stop - start;
    cout << "Execution time: " << duration.count() << " seconds\n";

    return 0;
}