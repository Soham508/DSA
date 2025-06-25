/* How many subsets of given array can be formed such that difference between sum of elements of subset1 
and sum of elements of subset2 is given difference.

Sum(S1) - Sum(S2) = D (given)
Sum(S1) + Sum(S2) = Sum(A) (total sum of array)
Sum(S1) = (Sum(A) + D) / 2
So, we need to find number of subsets of array whose sum is equal to (Sum(A) + D)/2.
*/

#include <iostream>
#include <vector>
using namespace std;

int numberOfSubSetGivenDiff(vector<int> nums, int target, int n, vector<vector<int>> dp){
    if(target==0){
        return 1;
    }
    if(n == 0){
        return 0;
    }

    if(dp[n][target] != -1){
        return dp[n][target];
    }
    
    if(nums[n-1] > target){
        return dp[n][target] = numberOfSubSetGivenDiff(nums, target, n-1, dp); 
    }
    else{
        return dp[n][target] = numberOfSubSetGivenDiff(nums, target-nums[n-1], n-1, dp) + numberOfSubSetGivenDiff(nums, target, n-1, dp);
    }

}

int main()
{
    vector<int> nums = {2,3,1,5,6,2};
    int n = nums.size();
    int diff = 1;
    int sum = 0;
    for(int i=0; i<n;i++){
        sum+=nums[i];
    }    
    int target = (sum+diff)/2;
    vector<vector<int>> dp(n+1, vector<int>(target+1,-1));

    if ((sum + diff) % 2 != 0) {
    cout << "Subset with given difference not possible." << endl;
    return 0;
}

    cout << "Number of Subset would be" << endl
         << numberOfSubSetGivenDiff(nums, target, n, dp);

    return 0;
}