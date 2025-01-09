#include <iostream>
#include <chrono>

using namespace std;

int _OP_COUNT = 0;

void bubbleSort(int* numArray, int size){
    for (int i = 0; i < size-1; ++i){
        bool swapped = false;
        for (int j = 0; j < size-i-1; ++j){
            ++_OP_COUNT;
            if(numArray[j] > numArray[j+1]){
                int temp = numArray[j];
                numArray[j] = numArray[j+1];
                numArray[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped){
            break;
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
    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    int numArray[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(numArray)/sizeof(numArray[0]);

    bubbleSort(numArray, size);
    printArray(numArray, size);
    cout << "Number of operations: " << _OP_COUNT << endl;

    // Stop measuring time
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = stop - start;
    std::cout << "Execution time: " << duration.count() << " seconds\n";

    return 0;
}