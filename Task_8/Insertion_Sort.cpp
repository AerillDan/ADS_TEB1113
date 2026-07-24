#include <iostream>
#include <utility>
using namespace std;

void insertionSort(int data[], int size) {
    for (int curr = 1; curr < size; curr++) {
        int currentVal = data[curr];   
        int prevIdx = curr - 1; 

        // Shift elements of the sorted segment to the right 
        // if they are greater than our current value
        while (prevIdx >= 0 && data[prevIdx] > currentVal) { 
            swap(data[prevIdx + 1], data[prevIdx]);
            prevIdx--;
        }

        // Lock the value into its proper sorted position
        data[prevIdx + 1] = currentVal;
    }
}

void showElements(int data[], int size) {
    for (int k = 0; k < size; k++) {
        cout << data[k] << " ";
    }
    cout << endl;
}

int main() {
    int sequence[] = {56, 72, 30, 15, 78, 54, 90};
    int totalElements = sizeof(sequence) / sizeof(sequence[0]);

    cout << "Unsorted layout: ";
    showElements(sequence, totalElements);

    insertionSort(sequence, totalElements);

    cout << "Result (Insertion Sort): ";
    showElements(sequence, totalElements);

    return 0;
}
