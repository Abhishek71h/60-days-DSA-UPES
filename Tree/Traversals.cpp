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

void levelOrderTraversal(Node* root) {
    vector<vector<int>> ans;
    queue<Node*> q;
    if(root == NULL) return;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++) {
            Node* temp = q.front();
            q.pop();
            level.push_back(temp -> data);
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
        ans.push_back(level);
    }
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) { 
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void inorderTraversal(Node* root) {
    if(root == NULL) return;
    // LNR
    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

void PreorderTraversal(Node* root) {
    if(root == NULL) return;
    // NLR
    cout << root -> data << " ";
    PreorderTraversal(root -> left);
    PreorderTraversal(root -> right);
}

void PostorderTraversal(Node* root) {
    if(root == NULL) return;
    // LRN
    PostorderTraversal(root -> left);
    PostorderTraversal(root -> right);
    cout << root -> data << " ";
}

int main() {
    Node* root = NULL;
    root = buildTree();
    cout << "Printing Level Order Traversal" << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << "Printing IN Order Traversal" << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "Printing Pre Order Traversal" << endl;
    PreorderTraversal(root);
    cout << endl;
    cout << "Printing Post Order Traversal" << endl;
    PostorderTraversal(root);
}