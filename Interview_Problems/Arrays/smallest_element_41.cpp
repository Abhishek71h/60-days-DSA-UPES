#include<iostream>
#include<vector>
using namespace std;
int smallestElement(vector<int>& arr, int n) {
    /*
    Algorithm -> Step(1) = Missing number lies between [1, n+1]
    Step(2) = Use the array itself as a hash
    Step(3) = Mark presence by making values -ve
    T.C = O(n) and S.C = O(n)
    */

    bool contains_one = false;
    for(int i=0; i<n; i++) {
        if(arr[i] == 1) contains_one = true;
        if(arr[i] <= 0 || arr[i] > n) arr[i] = 1;
    }
    if(!contains_one) return 1;
    for(int i=0; i<n; i++) {
        int index = abs(arr[i]) - 1;
        if(arr[index] < 0) continue;
        arr[index] *= -1;
    }
    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            return i+1;
        }
    }
    return n+1;
}
int main() {
    vector<int> arr = {3,4,-1,-2,1,5,16,0,2,0};
    int n = arr.size();
    int ans = smallestElement(arr, n);
    cout << "Answer is: " << ans << endl;
    return 0;
}