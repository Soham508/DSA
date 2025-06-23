/*
Coins array given with different denominations, find the minimum number of coins needed to make the target amount.
If it is not possible to make the target amount, return -1.

Its allowed to take a single coin (coin at same position) multiple times.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChangeHelper(vector<int>& coins, int n, int target, vector<vector<int>>& dp) {
    if (target == 0) return 0;            // Base case: no amount left, no coins needed
    if (n == 0) return INT_MAX;           // No coins left, cannot form amount
    if (dp[n][target] != -1) return dp[n][target];

    int notTake = coinChangeHelper(coins, n - 1, target, dp); // Skip this coin
    int take = INT_MAX;

    if (coins[n - 1] <= target) {
        int res = coinChangeHelper(coins, n, target - coins[n - 1], dp); // Use same coin again
        if (res != INT_MAX) take = 1 + res;
    }

    return dp[n][target] = min(take, notTake);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    int result = coinChangeHelper(coins, n, amount, dp);
    return (result == INT_MAX) ? -1 : result;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int minCoins = coinChange(coins, amount);
    if (minCoins == -1)
        cout << "Cannot make up the amount with given coins." << endl;
    else
        cout << "Minimum coins required: " << minCoins << endl;

    return 0;
}
