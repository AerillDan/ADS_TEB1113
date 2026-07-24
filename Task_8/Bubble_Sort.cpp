#include <iostream>
#include <utility> // For std::swap
using namespace std;

void bubbleSort(int data[], int size) {
    for (int step = 0; step < size - 1; step++) {
        bool hasSwapped = false;

        for (int idx = 0; idx < size - step - 1; idx++) {
            if (data[idx] > data[idx + 1]) {
                swap(data[idx], data[idx + 1]);
                hasSwapped = true;
            }
        }
        // If no two elements were swapped, the array is already sorted
        if (!hasSwapped) {
            break;
        }
    }
}

void displayArray(int data[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << (i < size - 1 ? ", " : " ");
    }
    cout << "]\n";
}

int main() {
    int numbers[] = {56, 72, 30, 15, 78, 54, 90};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "Original array: ";
    displayArray(numbers, length);

    bubbleSort(numbers, length);

    cout << "Sorted array (Bubble Sort): \n";
    displayArray(numbers, length);

    return 0;
}
