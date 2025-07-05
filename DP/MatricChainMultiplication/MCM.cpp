#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to compute the minimum number of multiplications needed
int matrixChainMemo(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == j) return 0; // Base case: single matrix

    if (dp[i][j] != -1) return dp[i][j]; // Return already computed value

    
    int minCost = INT_MAX;


    // Try placing parenthesis at different positions between i and j
    for (int k = i; k < j; ++k) {
        int cost = matrixChainMemo(i, k, arr, dp) +
                   matrixChainMemo(k + 1, j, arr, dp) +
                   arr[i - 1] * arr[k] * arr[j];

        minCost = min(minCost, cost);
    }

    return dp[i][j] = minCost;
}

int matrixChainMultiplication(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Call the memoized recursive function from 1 to n-1 (matrix indexing)
    return matrixChainMemo(1, n - 1, arr, dp);
}

int main() {
    // Example: dimensions of matrices A1(10x30), A2(30x5), A3(5x60)
    vector<int> arr = {10, 30, 5, 60};

    int result = matrixChainMultiplication(arr);
    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}
