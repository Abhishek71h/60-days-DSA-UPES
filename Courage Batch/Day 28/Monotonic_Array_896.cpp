/*Question: An array is monotonic if it is either monotone increasing or monotone decreasing.
An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true

Example 2:
Input: nums = [6,5,4,4]
Output: true

Example 3:
Input: nums = [1,3,2]
Output: false
 
Constraints:
1 <= nums.length <= 105
-105 <= nums[i] <= 105

Solution:
*/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool Increasing = false;
        bool Decreasing = false;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] < nums[i+1]) Increasing = true;
            else if(nums[i] > nums[i+1]) Decreasing = true;
        }
        if(Increasing == true && Decreasing == true) return false;
        return true;
    }
};