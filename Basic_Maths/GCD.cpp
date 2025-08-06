/*gcd(a,b) = gcd(a-b, b) a > b
gcd(a,b) = gcd(b-a, a) b > a
Apply this till one of the parameter becomes 0

Eg. gcd(72, 24) as a > b
    gcd(48, 24)
    gcd(24, 24)
    gcd(0, 24) => Ans is 24
*/

// iterative-way
class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        if(a == 0) return b;
        if(b == 0) return a;
        while(a > 0 && b > 0) {
            if(a > b) {
                a = a-b;
            } else b = b - a;
        }
        return a == 0 ? b : a;
    }
};

// Recursive-way
class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        if(a == 0) return b;
        if(b == 0) return a;
        int ans = 0;
        if(a > b) {
            ans = gcd(a-b, b);
        }
        else ans = gcd(b-a, a);
        return ans;
    }
};

