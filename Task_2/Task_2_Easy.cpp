#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// In-place sorting function using the Selection Sort strategy
void sortMatrixInPlace(vector<vector<int>>& mat) {
    int m = mat.size(); // Gets number of rows
    if (m == 0) return; // Guard clause for empty matrix
    int n = mat[0].size(); // Gets number of columns 
    
    // Total virtual elements = m * n = 3 * 4 = 12 total slots

    // Outer loop selects the target position to fill
    for (int i = 0; i < m * n - 1; i++) {
        
        // Inner loop scans everything ahead of 'i' to find smaller numbers
        for (int j = i + 1; j < m * n; j++) {
          
            // Convert current 1D flat indices back to actual 2D coordinates
            // Row coordinate: index / total columns (n)
            // Col coordinate: index % total columns (n)
            int row1 = i / n, col1 = i % n;
            int row2 = j / n, col2 = j % n;
            
            // If the element at the earlier position is larger, swap them
            if (mat[row1][col1] > mat[row2][col2]) {
                swap(mat[row1][col1], mat[row2][col2]);
                // Swapping modifies the matrix memory blocks directly in-place
            }
        }
    }
}

int main() {
    vector<vector<int>> mat{{5, 4, 7, 1}, {1, 3, 8, 2}, {2, 9, 6, 0}};
    
    // Sort the matrix structure directly without using temporary external vectors
    sortMatrixInPlace(mat);
    
    cout << "Sorted Matrix Will be:" << endl;
    for (const auto& row : mat) {
        for (int x : row) {
            cout << x << " "; 
        }
        cout << endl; 
    }

    return 0;
}