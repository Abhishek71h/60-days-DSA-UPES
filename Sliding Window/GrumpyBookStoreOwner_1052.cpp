/*Example 1:
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
Output: 16
Explanation:
The bookstore owner keeps themselves not grumpy for the last 3 minutes.
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

Example 2:
Input: customers = [1], grumpy = [0], minutes = 1
Output: 1
*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        /*int n = customers.size();
        int alwaysSatisfiedCustomers = 0;
        for(int i=0; i<n; i++) {
            if(grumpy[i] == 0) {
                alwaysSatisfiedCustomers = alwaysSatisfiedCustomers + customers[i];
            }
        }
        int maxSatisfied = INT_MIN;
        for(int i=0; i<=n-minutes; i++) {
            int extraSatisfiedCustomers = 0;
            for(int j=i; j<i+minutes; j++) {
                if(grumpy[j] == 1) {
                   extraSatisfiedCustomers = extraSatisfiedCustomers + customers[j]; 
                }
            }
            maxSatisfied = max(maxSatisfied, extraSatisfiedCustomers);
        }
        return alwaysSatisfiedCustomers + maxSatisfied;
        */
        
        // Optmize Approach using sliding Window
        int n = customers.size();
        int k = minutes;
        int alwaysSatisfiedCustomers = 0;
        for(int i=0; i<n; i++) {
            if(grumpy[i] == 0) {
                alwaysSatisfiedCustomers = alwaysSatisfiedCustomers + customers[i];
            }
        }
        int prev = 0;
        for(int i=0; i<k; i++) {
            if(grumpy[i] == 1) {
                prev = prev + customers[i];
            }
        }
        int maxSatisfied = prev;
        int i = 1;
        int j = k;
        while(j < n) {
            int curr = prev;
            if(grumpy[j] == 1) curr = curr + customers[j];
            if(grumpy[i-1] == 1) curr = curr - customers[i-1];
                maxSatisfied = max(maxSatisfied, curr);
                prev = curr;
                i++;
                j++;
        }
        return alwaysSatisfiedCustomers + maxSatisfied;
    }
};