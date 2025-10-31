#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<string> arr = {"flower","flow","flight"};
    int n = arr.size();
    string prefix = arr[0];
    for(int i=1; i<n; i++) {
        while(arr[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size()-1);
        }
    }
    cout << "Prefix is: " << prefix;
    return 0;
}