// Slow Exponentiation -> T.C = O(b)
#include<iostream>
using namespace std;
int slowExponentiation(int a, int b) {
    int ans = 1;
    for(int i=0; i<b; i++) {
        ans = ans * a;
    }
    return ans;
}
int main() {
    cout<< slowExponentiation(5,4) << endl;
    return 0;
}

// Fast Exponentiation -> T.C = O(logb)
#include<iostream>
using namespace std;
int fastExponentiation(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) {
            // odd
            ans = ans * a;
        }
        a = a*a;
        b = b/2;
    }
    return ans;
}
int main() {
    cout<< fastExponentiation(5,4) << endl;
    return 0;
}