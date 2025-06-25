#include<iostream>
#include<vector>
using namespace std;

  int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        while(start<=end){
             
        int mid = start+(end-start)/2;

        if(nums[mid]!= nums[mid-1] && nums[mid]!=nums[mid+1]){
            return mid;
        }

        if(nums[mid] == nums[mid-1]){
            end = mid-1;
        }

        }
        return start;
    }

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = singleNonDuplicate(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

