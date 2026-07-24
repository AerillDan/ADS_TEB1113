#include <iostream>
#include <utility>
using namespace std;

void selectionSort(int data[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int targetMinIdx = step; // Assume the current index holds the smallest value

        // Search the rest of the array for a smaller value
        for (int searchIdx = step + 1; searchIdx < size; searchIdx++) {
            if (data[searchIdx] < data[targetMinIdx]) {
                targetMinIdx = searchIdx;
            }
        }

        // Only swap if we actually found a smaller element
        if (targetMinIdx != step) {
            swap(data[step], data[targetMinIdx]);
        }
    }
}

void renderArray(int data[], int size) {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << "\n";
}

int main() {
    int vals[] = {56, 72, 30, 15, 78, 54, 90};
    int count = sizeof(vals) / sizeof(vals[0]);

    cout << "Before Sorting: ";
    renderArray(vals, count);

    selectionSort(vals, count);

    cout << "After Sorting (Selection Sort): ";
    renderArray(vals, count);

    return 0;
}
