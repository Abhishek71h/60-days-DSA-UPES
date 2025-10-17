// BackTracking is a specific form of Recursion where we explore all possible solutions

#include<iostream>
using namespace std;
void getAllPermutation(string str, int n, int i) {
    if(i >= n) {
        cout << str << " ";
        return;
    }
    for(int j=i; j<n; j++) {
        swap(str[i], str[j]);
        getAllPermutation(str, n, i+1);
        // backtrack
        swap(str[i], str[j]);
    }
}
int main() {
    string str = "abc";
    int n = str.size();
    int i = 0;
    getAllPermutation(str, n, i);
    return 0;
}