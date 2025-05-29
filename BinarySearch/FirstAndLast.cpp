#include <vector>
#include <iostream>
using namespace std;

    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1; // search on the left side
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1; // search on the right side
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int main() {
    vector<int> nums = {2,3,5,7,7,7,8,8,10};
    int target = 7;
    int first = findFirst(nums, target);
    int last = findLast(nums, target);
    cout << "First occurrence of " << target << " is at index: " << first << endl;
    cout << "Last occurrence of " << target << " is at index: " << last << endl;
    
    return 0;
}
