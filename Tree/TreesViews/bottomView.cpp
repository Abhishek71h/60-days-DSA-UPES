#include<iostream>
#include<map>
#include<queue>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
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

void printBottomView(Node* root) {
    if(root == NULL) {
        return;
    }
    map<int, int> bottomNode;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        bottomNode[hd] = frontNode -> data;

        if(frontNode -> left) {
            q.push({frontNode -> left, hd-1});
        }

        if(frontNode -> right) {
            q.push({frontNode -> right, hd+1});
        }
    }
    for(auto i: bottomNode) {
        cout << i.first << " --> " << i.second << endl;
    }
}
int main() {
    Node* root = buildTree();
    printBottomView(root);
    return 0;
}