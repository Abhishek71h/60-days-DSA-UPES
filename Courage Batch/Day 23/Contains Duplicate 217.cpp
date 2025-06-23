/*Question: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109

Solution:
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        // Brute-Force Approach
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         if(nums[i] == nums[j]) return true;
        //     }
        // }
        // return false;

        // Optimal Approach
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++) {
            if(nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};