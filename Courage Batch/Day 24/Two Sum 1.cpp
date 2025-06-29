/*Question: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

Solution:
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* Brute-Force Approach
        int n = nums.size();
        vector<int>result;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
        */
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++) {
            int difference = target - nums[i];
            if(mp.find(difference) != mp.end()) {
                return {mp[difference], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};