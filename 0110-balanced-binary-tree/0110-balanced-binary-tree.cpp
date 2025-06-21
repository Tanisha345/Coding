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



int solve(TreeNode* root){
    if(!root) return 0;

    int left= solve(root->left);
    int right= solve(root->right);

    if(abs(right-left)>1) return -1;
    return 1+max(left, right);
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(solve(root)==-1) return false;
        return true;
    }
};