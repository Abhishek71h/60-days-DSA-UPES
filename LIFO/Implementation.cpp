// Stack is a data Structure where data is stored in Last In First Out (LIFO) order.
// Stack Overflow is a condition when the size of stack is full and it can not store the next element.
#include<iostream>
using namespace std;
class Stack {
    public:
    // Using array
    int *arr; // pointer 
    int size; // array size
    int top; // index of top element in stack
    Stack(int size) {
        arr = new int[size];
        this -> size = size;
        top = -1;
    }

    void push(int data) {
        if(size - top > 1) {
            // space available
            top++;
            arr[top] = data;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if(top == -1) {
            cout << "Stack Underflow" << endl;
        }
        else {
            top--;
        }
    }

    int getTop() {
        if(top == -1) {
            cout << "No element in Stack" << endl;
        }
        else {
            return arr[top];
        }
    }

    // Number of elements present in stack
    int getSize() {
        return top + 1;
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else return false;
    }
};
int main() {
    // Creation
    Stack st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << "Size of the Stack is: " << st.getSize();
    cout << endl;
    // Printing 
    while(!st.isEmpty()) {
        cout << st.getTop() << " ";
        st.pop();
    }
    cout << endl;
    cout << "Size of the Stack is: " << st.getSize();
}