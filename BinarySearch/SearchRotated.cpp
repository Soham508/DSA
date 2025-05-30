#include<iostream>
#include<vector>
using namespace std;

int Search(vector<int>& nums, int target){
    int start=0;
    int end=nums.size()-1;
    
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            return mid;
        }

        else if(nums[mid] >= nums[start]){
            if(nums[mid] >= target && nums[start] <= target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(nums[mid] <= target && nums[end] >= target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }

        }

    }

        return -1;
}

int main(){
    vector<int> nums = {7,9,0,1,2,3,5,6};
    int target = 3;
    int ans = Search(nums, target);
    cout<<ans<<endl;
    
    return 0;
}