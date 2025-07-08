/*Question: You are given an integer n. Your task is to determine whether it is a palindrome.
A number is considered a palindrome if it reads the same backward as forward, like the string examples "MADAM" or "MOM".

Examples:
Input: n = 555
Output: true
Explanation: The number 555 reads the same backward as forward, so it is a palindrome.

Input: n = 123
Output: false
Explanation: The number 123 reads differently backward (321), so it is not a palindrome.

Input: n = 1221
Output: true

Constraints:
1 ≤ n ≤ 109

Solution:
*/
class Solution {
  public:
  int reverse(int n) {
      int digit = 0;
      while(n != 0) {
          int last_Digit = n%10;
          digit = digit*10 + last_Digit;
          n = n/10;
      }
      return digit;
  }
    bool isPalindrome(int n) {
        // code here.
        int original_number = n;
        int reverse_number = reverse(n);
        if(original_number == reverse_number) return true;
        else return false;
    }
};