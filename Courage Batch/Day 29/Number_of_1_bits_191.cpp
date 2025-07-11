/*Question: Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.

Example 2:
Input: n = 128
Output: 1
Explanation:
The input binary string 10000000 has a total of one set bit.

Example 3:
Input: n = 2147483645
Output: 30
Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

Constraints:
1 <= n <= 231 - 1

Solution:
*/
class Solution {
public:
    int hammingWeight(int n) {
        /*Approach 1
        int count = 0;
        for(int i=31; i>=0; i--) {
            if(((n>>i)&1) == 1) count++;
        }
        return count;
        */

        /*Approach 2
        int count = 0;
        while(n != 0) {
            n = (n & (n-1));
            count++;
        }
        return count;
        */

        //Approach 3
        int count = 0;
        while(n != 0) {
            count = count + (n%2);
            n = n/2;
        }
        return count;
    }
};