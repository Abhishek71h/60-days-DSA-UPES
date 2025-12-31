// Find middle element in stack
#include<iostream>
#include<stack>
using namespace std;
void getMiddle(stack<int>& st, int totalSize) {
    // base case
    if(st.size() == 0) {
        cout << "Empty Stack" << endl;
    }
    if(st.size() == (totalSize/2)+1) {
        cout << "Middle Element of Stack is: " << st.top();
        return;
    }
    int temp = st.top();
    st.pop();
    getMiddle(st, totalSize);
    st.push(temp);
}
int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    int totalSize = st.size();
    getMiddle(st, totalSize);
}
