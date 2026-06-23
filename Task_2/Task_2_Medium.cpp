#include <iostream>
#include <vector>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    // Binary search boundaries across columns
    int low = 0, high = m - 1;
    
    // Fallback value representing negative infinity for edge boundaries
    int mini = int(-1e9);

    while (low <= high) {
        int mid = (low + high) / 2;

        // Find the maximum element in the current column.
        // This eliminates checking the top and bottom neighbors later.
        int maxRow = 0;
        for (int i = 1; i < n; ++i) {
            if (mat[i][mid] > mat[maxRow][mid])
                maxRow = i;
        }

        // Fetch horizontal neighbors; use -∞ if they are out of matrix bounds
        int left = (mid > 0) ? mat[maxRow][mid - 1] : mini;
        int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : mini;

        // If the element is greater than both left and right neighbors, it's a peak
        if (mat[maxRow][mid] >= left && mat[maxRow][mid] >= right)
            return {maxRow, mid};

        // If the right neighbor is larger, a peak must exist in the right half
        else if (right > mat[maxRow][mid])
            low = mid + 1;

        // If the left neighbor is larger, a peak must exist in the left half
        else
            high = mid - 1;
    }

    return {-1, -1};
}

int main() {
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<int> peak = findPeakGrid(mat);
    cout << peak[0] << " " << peak[1] << endl;
    return 0;
}