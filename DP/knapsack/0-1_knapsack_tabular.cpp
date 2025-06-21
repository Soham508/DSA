#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0-1 Knapsack problem using bottom-up DP
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // Create a 2D dp table of size (n+1) x (W+1)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Include the item or exclude it, take the max
                dp[i][w] = max(dp[i - 1][w],
                               values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // Item is too heavy, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The answer is in dp[n][W]
    return dp[n][W];
}

int main() {
    // Example usage
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int W = 5;  // Capacity of knapsack
    int n = weights.size();

    int maxVal = knapsack(W, weights, values, n);
    cout << "Maximum value in knapsack = " << maxVal << endl;

    return 0;
}
