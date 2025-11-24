#include<iostream>
#include<queue>
#include<map>
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

void printTopView(Node* root) {
    if(root == NULL) return;

    // Create a map for storing HD --> topNode -> data
    map<int, int> topNode;

    // Level Order
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode -> data;
        }

        if(frontNode -> left) {
            q.push({frontNode->left, hd-1});
        }

        if(frontNode -> right) {
            q.push({frontNode->right, hd+1});
        }
    }

    cout << "Printing Top View of Tree is: " << endl;
    for(auto i: topNode) {
        cout << i.first << " -> " << i.second << endl;
    }
}
int main() {
    Node* root = NULL;
    root = buildTree();
    printTopView(root);
}