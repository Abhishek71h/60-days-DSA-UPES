/*Question: Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0

Constraints:
0 <= n <= 5 * 106

Solution:
*/
class Solution {
public:
    bool validPrime(int n) {
        if(n == 0 || n == 1) {
            return false;
        }
        for(int i=2; i*i<=n; i++) {
            if(n%i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        if(n == 0 || n == 1) {
            return 0;
        }
        int count = 0;
        for(int i=2; i<n; i++) {
            if(validPrime(i)) {
                count++;
            }
        }
        return count;
    }
};