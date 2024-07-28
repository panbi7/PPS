#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left;  // left is the insertion point
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Index for " << target1 << " is: " << solution.searchInsert(nums1, target1) << endl;  // Output: 2

    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Index for " << target2 << " is: " << solution.searchInsert(nums2, target2) << endl;  // Output: 1

    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Index for " << target3 << " is: " << solution.searchInsert(nums3, target3) << endl;  // Output: 4

    return 0;
}