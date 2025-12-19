#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    cout << "Enter data for left part of " << data << " node:\n";
    root->left = buildTree();

    cout << "Enter data for right part of " << data << " node:\n";
    root->right = buildTree();
    return root;
}

void printRightView(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        // First node of this level is the left view node
        for (int i = 0; i < levelSize; i++) {
            Node* frontNode = q.front();
            q.pop();

            // take the first element of this level
            if (i == 0) {
                cout << frontNode->data << " ";
            }

            if (frontNode->right) q.push(frontNode->right);
            if (frontNode->left) q.push(frontNode->left);
        }
    }
}

int main() {
    Node* root = buildTree();
    cout << "\nRight View: ";
    printRightView(root);
    return 0;
}
