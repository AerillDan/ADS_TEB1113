#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define N 5

int findMaxValue(int mat[][N])
{
    // Instead of a full 2D grid, we only keep track of the row below us (temp1)
    // and the current row we are building (temp2)
    vector<int> temp1(N), temp2(N);
    
    // Initialize the bottom-right corner value
    temp1[N - 1] = mat[N - 1][N - 1];

    // Pre-fill temp1 with the maximum values found in the very last row (bottom-up)
    for (int j = N - 2; j >= 0; j--)
        temp1[j] = max(temp1[j + 1], mat[N - 1][j]);

    int maxValue = INT_MIN;

    // Loop through the remaining rows from bottom to top
    for (int i = N - 2; i >= 0; i--) {
        
        // The last column element of the current row handles boundaries
        temp2[N - 1] = max(temp1[N - 1], mat[i][N - 1]);
        
        for (int j = N - 2; j >= 0; j--) {
            // Update the global maximum difference using the pre-calculated 
            // max values sitting in the row directly below and to the right
            maxValue = max(maxValue, temp1[j + 1] - mat[i][j]);
            
            // Maintain the maximum tracking window for the current row
            temp2[j] = max({ mat[i][j], temp1[j], temp2[j + 1] });
        }
        
        // Space Optimization Trick: Copy the current row state (temp2) into temp1.
        // This drops the previous row from memory since we don't need it anymore.
        temp1 = temp2;
    }

    return maxValue;
}

int main()
{
    int mat[N][N] = { { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 } };
                      
    cout << "Maximum Value is " << findMaxValue(mat) << endl;
    return 0;
}