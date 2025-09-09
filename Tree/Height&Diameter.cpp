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

int Height(Node* root) {
    if(root == NULL) return 0;
    // For Number of edges
    //if(root == NULL) return -1;
    int leftHeight = Height(root -> left);
    int rightHeight = Height(root -> right);
    int ans = 1 + max(leftHeight, rightHeight);
    return ans;
}
int diameter(Node* root) {
    // For Number of Edges
    if(root == NULL) return 0;
    int leftDiameter = diameter(root -> left);
    int rightDiameter = diameter(root -> right);
    int TotalDiameter = Height(root->left) + Height(root->right);
    // For Number of Nodes
    // int TotalDiameter = 1 + Height(root->left) + Height(root->right);
    int ans = max(TotalDiameter, max(leftDiameter, rightDiameter));
    return ans;
    }

int main() {
    Node* root = NULL;
    root = buildTree();
    cout << "Printing Level Order Traversal" << endl;
    levelOrderTraversal(root);
    cout << "Height is: " << Height(root) << endl;
    cout << "Diameter is: " << diameter(root);
}