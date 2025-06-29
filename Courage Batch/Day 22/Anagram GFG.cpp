/*Question: Anagram
Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, "act" and "tac" are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.
Note: You can assume both the strings s1 & s2 are non-empty.

Examples :
Input: s1 = "geeks", s2 = "kseeg"
Output: true
Explanation: Both the string have same characters with same frequency. So, they are anagrams.

Input: s1 = "allergy", s2 = "allergic"
Output: false
Explanation: Characters in both the strings are not same, so they are not anagrams.
Input: s1 = "g", s2 = "g"
Output: true
Explanation: Character in both the strings are same, so they are anagrams.

Constraints:
1 ≤ s1.size(), s2.size() ≤ 105

Soultion:
*/
class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        int hash[256] = {0};
        int n = s1.size();
        int m = s2.size();
        for(int i=0; i<n; i++) {
            hash[s1[i]]++;
        }
        for(int i=0; i<m; i++) {
            hash[s2[i]]--;
        }
        for(int i=0; i<256; i++) {
            if(hash[i] != 0) return false;
        }
        return true;
    }
};