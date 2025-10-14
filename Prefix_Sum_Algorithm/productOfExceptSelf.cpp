#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    vector<int> pre(n);
    vector<int> suff(n);

    // Prefix product
    pre[0] = 1;
    int p = arr[0];
    for (int i=1; i<n; i++) {
        pre[i] = p;
        p = p * arr[i];
    }

    // Suffix product
    p = arr[n-1];
    suff[n-1] = 1;
    for (int i=n-2; i>=0; i--) {
        suff[i] = p;
        p = p * arr[i];
    }

    // Final answer
    for (int i = 0; i < n; i++) {
        pre[i] = pre[i] * suff[i];
    }
    cout << "Answer is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << pre[i] << " ";
    }
    return 0;
}
