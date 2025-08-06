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
    vector<bool>Sieve(int n) {
        vector<bool>sieve(n+1, true);
        sieve[0] = false;
        sieve[1] = false;
        for(int i=2; i*i<n; i++) {
            if(sieve[i] == true) {
                int j = i*i;
                while(j<n) {
                    sieve[j] = false;
                    j += i;
                }
            }
        }
        return sieve;
    }
    int countPrimes(int n) {
        vector<bool>sieve = Sieve(n);
        int count = 0;
        for(int i=0; i<n; i++) {
            if(sieve[i]) {
                count++;
            }
        }
        return count;
    }
};