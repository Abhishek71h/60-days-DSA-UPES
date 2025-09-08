#include<iostream>
#include<vector>
using namespace std;
int main() {
    int arr[] = {1,-2,3,-7,4,5,9,-1,8};
    int n = 9;
    int k = 3;
    vector<int>ans;
    for(int i=0; i<=n-k; i++) {
        for(int j=i; j<i+k; j++) {
            if(arr[j] < 0) {
                ans.push_back(arr[j]);
                break;
            }
        }
    }
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
}