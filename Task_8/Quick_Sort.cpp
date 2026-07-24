#include <iostream>
#include <utility>
using namespace std;

int partitionArray(int data[], int start, int end) {
    int pivotValue = data[start];  
    int leftPtr = start + 1;       
    int rightPtr = end;

    while (leftPtr <= rightPtr) { 
        // Advance left pointer while elements are smaller than pivot
        while (leftPtr <= end && data[leftPtr] < pivotValue) leftPtr++;

        // Retreat right pointer while elements are larger than pivot
        while (rightPtr >= start + 1 && data[rightPtr] > pivotValue) rightPtr--;

        // Swap if pointers haven't crossed
        if (leftPtr < rightPtr) { 
            swap(data[leftPtr], data[rightPtr]); 
            leftPtr++;
            rightPtr--;
        }
    }

    // Place the pivot in its final sorted position
    swap(data[start], data[rightPtr]); 
    return rightPtr;               
}

void quickSort(int data[], int start, int end) {
    if (start < end) {
        int splitPoint = partitionArray(data, start, end);

        quickSort(data, start, splitPoint - 1);  // Sort the left partition
        quickSort(data, splitPoint + 1, end);    // Sort the right partition
    }
}

void printData(int data[], int size) {
    for (int i = 0; i < size; i++)
        cout << data[i] << " | ";
    cout << endl;
}

int main() {
    int dataset[] = {56, 72, 30, 15, 78, 54, 90};
    int size = sizeof(dataset) / sizeof(dataset[0]);

    cout << "Starting array: \n";
    printData(dataset, size);

    quickSort(dataset, 0, size - 1); 

    cout << "Finished array (Quick Sort): \n";
    printData(dataset, size);

    return 0;
}
