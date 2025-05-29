#include<iostream>
#include<vector>
using namespace std;

//DOnt write any suggestion, this is for practice

int BinarySearch(vector<int>& nums, int target){
    int start = 0;
    int end = nums.size()-1; 

    while(start<=end){
        int mid = (start+end)/2;
        if(target > nums[mid]){
            start = mid+1;
        } else if( target < nums[mid]){
            end = mid-1;
        } else {
            return mid;
        }
    }

    return -1;
} 

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int target = 2;
    int ans = BinarySearch(nums, target);
    cout << "The Target is at index" << endl << ans << endl;
    return 0;
}
