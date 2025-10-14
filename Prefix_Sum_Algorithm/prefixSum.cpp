#include<iostream>
#include<vector>
using namespace std;
vector<int>runningSum(vector<int>& arr, int n) {
    /* Method 1: It has S.C O(n)
    vector<int>run(n);
    run[0] = arr[0];
    for(int i=1; i<n; i++) {
        run[i] = arr[i] + run[i-1];
    }
    return run;
    */

    // Method 2:
   for(int i=1; i<n; i++) {
    arr[i] = arr[i-1] + arr[i];
   }
   return arr;
}
int main() {
    vector<int>arr = {1,2,3,4};
    int n = arr.size();
    cout << "Array is: " << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    arr = runningSum(arr, n);
    cout << "Prefix Sum is: " << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}