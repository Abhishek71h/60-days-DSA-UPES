/*Question: The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 
Constraints:
1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.

Solution:
*/


/* Code for finding Next Greatest Element using Stack data Structure
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    int n = arr.size();
    stack<int>s;
    vector<int>result(n);
    for(int i=n-1; i>=0; i--) {
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            result[i] = -1;
        }
        else {
            result[i] = s.top();
        }
        s.push(arr[i]);
    }
    cout << "Printing next Greater Element using stack" << endl;
    for(auto val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Brute-Force Approach
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++) {
            int num = nums1[i];
            bool found = false;
            int nextGreater = -1;
            for(int j=0; j<nums2.size(); j++) {
                if(nums2[j] == num) {
                    found = true;
                }
                if(found && nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
        /*unordered_map<int, int>mp;
        stack<int>s;
        for(int i=nums2.size()-1; i>=0; i--) {
            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if(s.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0; i<nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
        */
    }
};