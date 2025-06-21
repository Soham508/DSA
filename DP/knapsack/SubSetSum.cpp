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

bool SubSetSum(vector<int>& nums, int sum, int n){
    if(sum == 0)
        return true;

    if(n == 0)
        return false;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    if(nums[n-1] > sum)
        return dp[n][sum] = SubSetSum(nums, sum, n-1);

    else{
    return dp[n][sum] = SubSetSum(nums, sum, n-1) || SubSetSum(nums, sum - nums[n-1], n-1);
    }
    
}

// bool TabularSubSetSum(vector<int>& nums, int sum, int n){
//     for(int i=0; i < n+1; i++){
//         for(int j=0; j < sum+1; j++){
//             if(i==0){                            // if number of items is 0 we can't make any sum
//                 dp[i][j] = false;
//             }
//             if(j==0){                            // if sum is 0 we can always have null subset
//                 dp[i][j] = true;
//             }
//             if(nums[i-1] > j){
//                 dp[i][j] = dp[i-1][j];
//             }
//             else{
//                 dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
//             }
//         }
//     }
// }

int main() {
    vector<int> nums = {1, 2, 4, 3, 5, 2};

    memset(dp, -1, sizeof(dp));

    if(SubSetSum(nums, 14, nums.size() - 1) == true)
        cout << "Subset exists" << endl;
    else
        cout << "Subset does not exist" << endl;

    return 0;
}

