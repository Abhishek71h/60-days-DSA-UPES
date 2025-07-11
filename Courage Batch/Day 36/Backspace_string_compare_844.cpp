/*Question: Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 
Constraints:
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.

Solution:
*/

class Solution {
public:
    string make_string(string s) {
        string temp = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] != '#') {
                temp.push_back(s[i]);
            }
            else if(!temp.empty()) {
                temp.pop_back();
            }
        }
        return temp;
    }
    bool backspaceCompare(string s, string t) {
        string first = make_string(s);
        string second = make_string(t);
        if(first == second) return true;
        else return false;
    }
};