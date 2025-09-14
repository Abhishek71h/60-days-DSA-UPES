/*Question: Given n items where each item has some weight and profit associated with it and also given a bag with capacity W, 
[i.e., the bag can hold at most W weight in it]. 
The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible. 
Constraint: The constraint here is we can either put an item completely into the bag or cannot put it at all 
[It is not possible to put a part of an item into the bag].
Eg: Input:  capacity = 4, value[] = [1, 2, 3], weight[] = [4, 5, 1]
Output: 3
Explanation: There are two items which have weight less than or equal to 4. If we select the item with weight 4, the possible profit is 1. And if we select the item with weight 1, the possible profit is 3. So the maximum possible profit is 3. 
Note that we cannot put both the items with weight 4 and 1 together as the capacity of the bag is 4.
*/

#include<iostream>
#include<vector>
using namespace std; 
int solveByRecursion(int weight[], int value[], int index, int capacity) {
    // Base Case
    if(index == 0) {
        if(weight[0] <= capacity) {
            return value[0];
        }
        else return 0;
    }
    int include = 0;
    if(weight[index] <= capacity) {
        include = value[index] + solveByRecursion(weight, value, index-1, capacity-weight[index]);
    }
    int exclude = solveByRecursion(weight, value, index-1, capacity);
    int ans = max(include, exclude);
    return ans;
}
int topDownApproach(int weight[], int value[], int index, int capacity, vector<vector<int>> dp) {
    if(index == 0) {
        if(weight[0] <= capacity) {
            return value[0];
        }
        else return 0;
    }
    if(dp[index][capacity] != -1) {
        return dp[index][capacity];
    }
    int include = 0;
    if(weight[index] <= capacity) {
        include = value[index] + topDownApproach(weight, value, index-1, capacity-weight[index], dp);
    }
    int exclude = topDownApproach(weight, value, index-1, capacity, dp);
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];  
}
int bottomUpApproach(int weight[], int value[], int n, int capacity) {
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= w) {
            dp[0][w] = value[0];
        }
        else dp[0][w] = 0;
    }
    for(int index=1; index<n; index++) {
        for(int wt=0; wt<=capacity; wt++) {
            int include = 0;
            if(weight[index] <= wt) {
                include = value[index] + dp[index-1][wt-weight[index]];
            }
            int exclude = dp[index-1][wt];
            dp[index][wt] = max(include, exclude);   
        }
    }
    return dp[n-1][capacity];
}
int spaceOptimization(int weight[], int value[], int n, int capacity) {
    vector<int>prev(capacity+1, 0);
    vector<int>curr(capacity+1, 0);
    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= w) {
            prev[w] = value[0];
        }
        else prev[w] = 0;
    }
    for(int index=1; index<n; index++) {
        for(int wt=0; wt<=capacity; wt++) {
            int include = 0;
            if(weight[index] <= wt) {
                include = value[index] + prev[wt-weight[index]];
            }
            int exclude = prev[wt];
            curr[wt] = max(include, exclude);   
        }
        prev = curr;
    }
    return prev[capacity];    
}
int main() {
    int weight[] = {4,5,1};
    int value[] = {1,2,3};
    int n = 3;
    int capacity = 4;
    // int ans = solveByRecursion(weight, value, n-1, capacity);
    // cout << "Answer is: " << ans;

    // vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    // int ans = topDownApproach(weight, value, n-1, capacity, dp);
    // cout << "Answer is: " << ans;

    // int ans = bottomUpApproach(weight, value, n, capacity);
    // cout << "Answer is: " << ans;

    int ans = spaceOptimization(weight, value, n, capacity);
    cout << "Answer is: " << ans;
    return 0;
}