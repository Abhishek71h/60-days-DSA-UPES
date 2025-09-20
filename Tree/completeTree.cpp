#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    cout << "Enter data for left part of " << data << " node " << endl;
    root -> left = buildTree();
    cout << "Enter data for right part of " << data << " node " << endl;
    root -> right = buildTree();
    return root;
}

bool completeTree(Node* root) {
    queue<Node*> q;
    bool past = false;
    q.push(root);
    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        if(front == NULL) {
            past = true;
        }
        else {
            if(past == true) {
                return false;
            }
            q.push(front -> left);
            q.push(front -> right);
        }
    }
    return true;
}

int main() {
    Node* root = NULL;
    root = buildTree();
    bool ans = completeTree(root);
    if(ans) {
        cout << "Yes it is a complete Binary Tree" << endl;
    }
    else cout << "No it is not a complete Binary Tree" << endl;
}