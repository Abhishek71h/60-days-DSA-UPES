/*Question: Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 
Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

Solution:
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Brute-Force Approach
        int n = nums.size();
        vector<int>ans;
        for(int i=0; i<n; i++) {
            int ans1 = nums[i]*nums[i];
            ans.push_back(ans1);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};