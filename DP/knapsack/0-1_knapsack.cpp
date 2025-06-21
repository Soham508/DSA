/*A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items. Its weight is given by the ‘wt’
 array and its value by the ‘val’ array. He can either include an item in its knapsack or exclude it but can’t partially have 
 it as a fraction. We need to find the maximum value of items that the thief can steal. */

#include<iostream>
#include <vector>
#include <cstring>
using namespace std;


const int MAX_ITEMS = 1001;
const int MAX_WEIGHT = 1001;
int dp[MAX_ITEMS][MAX_WEIGHT];

int knapsack(vector<int>& wt, vector<int>& val, int n, int W ){
    if(n==0 || W==0){
        return 0;
    }

    if(dp[n][W] != -1){
        return dp[n][W];
    }

    if(wt[n-1] > W){ 
        return dp[n][W] = knapsack(wt, val, n-1, W);
    }
    else{
        return dp[n][W] = max(knapsack(wt, val, n - 1, W), val[n - 1] + knapsack(wt, val, n - 1, W - wt[n - 1]));
    }
    
}



int main() {
    vector<int> wt = {1, 2, 4, 3, 5, 2};
    vector<int> val = {5, 4, 8, 6, 2, 8};
    int W = 5;
    int n = wt.size();

    memset(dp, -1, sizeof(dp));

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

    return 0;
}
