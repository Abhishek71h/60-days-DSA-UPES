#include<iostream>
#include<vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& arr, int n) {
    // Time: O(n) and Space: O(n)
    // It can be done by prefix and suffix array
    vector<int> pre(n);
    vector<int> suff(n);

    // Step(1) = filling the prefuix array
    int p = arr[0];
    pre[0] = 1;
    for(int i=1; i<n; i++) {
        pre[i] = p;
        p = p * arr[i];
    }

    // Step(2) = filling suffix array
    p = arr[n-1];
    suff[n-1] = 1;
    for(int i=n-2; i>=0; i--) {
        suff[i] = p;
        p = p * arr[i];
    }

    // Step(3) = * both result and store in pre array
    for(int i=0; i<n; i++) {
        pre[i] *= suff[i];
    }
    return pre;
}
int main() {
    vector<int> arr = {1,2,3,4};
    int n = arr.size();
    vector<int> ans = productExceptSelf(arr, n);
    cout << "Printing Product of Array Except Self: " << endl;
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}