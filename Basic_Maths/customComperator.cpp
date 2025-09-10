#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool customCompare(int a, int b) {
    int sum1 = 0;
    int sum2 = 0;
    while(a != 0) {
        sum1 = sum1 + a%10;
        a = a/10;
    }
    while(b != 0) {
        sum2 = sum2 + b%10;
        b = b/10;
    }
    if(sum1 < sum2) return true;
    if(sum1 > sum2) return false;
    return (a < b);
}
void solve(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end(), customCompare);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr = {13, 27, 59, 47, 107, 51};
    int n = arr.size();
    solve(arr, n);
    return 0;
}
