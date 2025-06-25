#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (index == 0) return nums[0] == target;
    
    if (dp[index][target] != -1) return dp[index][target];

    bool notTake = subsetSum(index - 1, target, nums, dp);
    bool take = false;
    if (nums[index] <= target)
        take = subsetSum(index - 1, target - nums[index], nums, dp);

    return dp[index][target] = take || notTake;
}

bool canPartition(vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) totalSum += num;

    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2;
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return subsetSum(n - 1, target, nums, dp);
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    
    if (canPartition(nums))
        cout << "Can be partitioned into two subsets of equal sum." << endl;
    else
        cout << "Cannot be partitioned into two subsets of equal sum." << endl;

    return 0;
}

