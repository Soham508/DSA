/*
Same as KnapSack, here we are just allowed to select element multiple times. 
*/

#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int n, int W, vector<vector<int>>& dp){
    if(n == 0 || W == 0){
        return 0;
    }

    if(dp[n][W] != -1){
        return dp[n][W];
    }

    if(wt[n-1]> W){
        return dp[n][W] = knapsack(wt, val, n-1, W, dp);
    }else
    { // We are allowed to select element multiple times
        return dp[n][W] = max(val[n-1] + knapsack(wt, val, n, W-wt[n-1], dp), knapsack(wt, val, n-1, W, dp));
    }
}

int main(){
    vector<int> wt = {1, 3, 4, 5, 6};
    vector<int> val = {1, 4, 5, 7, 10};
    int W = 10;
    int n = wt.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    int ans = knapsack(wt, val, n, W, dp);
    cout << ans << endl;
    return 0;
}