#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int maximumSumSubarray(vector<int>& arr, int n, int k) {
    /* Brute-force Approach
    int maxSum = INT_MIN;
    for(int i=0; i<=n-k; i++) {
        int sum = 0;
        for(int j=i; j<i+k; j++) {
            sum = sum + arr[j];
        }
        maxSum = max(maxSum, sum);
    }
    cout << "Maximum Sum in Subarray of size k is: " << maxSum;
    */

    // Optimize Approach using Sliding Window Approach
    int maxSum = INT_MIN;
    int currSum = 0;
    for(int i=0; i<k; i++) {
        currSum = currSum + arr[i];
    }
    maxSum = currSum;
    int i = 1;
    int j = k;
    while(j < n) {
        currSum = currSum + arr[j] - arr[i-1];
        maxSum = max(maxSum, currSum);
        i++;
        j++;
    }
    cout << "Maximum Sum in Subarray of size k is: " << maxSum;
}
int main() {
    vector<int>arr = {7,1,2,5,8,4,9,3,6};
    int n = arr.size();
    int k = 3;
    return maximumSumSubarray(arr, n, k);
}