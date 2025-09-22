/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// A height-balanced binary tree is a binary tree 
// in which the depth of the two subtrees of every node never differs by more than one.
// Fastest Method -> T.C is O(n) and S.C is O(n) due to recursive stack
class Solution {
public:
    bool balance = true;
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);
        int diff = abs(leftHeight - rightHeight);
        if(diff > 1) {
            balance = false;
        }
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return balance;
    }
};