#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int longestConsecutive(vector<int>& nums, int n) {
    unordered_map<int, bool> mp;
    for(int i=0; i<n; i++) {
        mp[nums[i]] = true;
    }
    for(int i=0; i<n; i++) {
        if(mp.find(nums[i]-1) != mp.end()) {
            mp[nums[i]] = false;
        }
    }
    int maxLength = 0;
    int Starting = 0;
    for(auto& it: mp) {
        if(it.second == true) {
            int count = 0;
            int starting = 0;
            while(mp.find(it.first + count) != mp.end()) {
                count++;
            }
            if(count > maxLength) {
                maxLength = count;
                Starting = it.first;
            }
        }
    }
    cout << "Printing Longest Consecutive Sequence: " << endl;
    for(int i=Starting; i<Starting + maxLength; i++) {
        cout << i << " ";
    } cout << endl;
    return maxLength;
}
int main() {
    vector<int> nums = {2,12,9,16,10,5,3,20,25,11,1,8,6};
    int n = nums.size();
    int ans = longestConsecutive(nums, n);
    cout << "Answer is: " << ans;
    return 0;
}