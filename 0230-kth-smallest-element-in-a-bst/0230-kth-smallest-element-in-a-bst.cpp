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


void solve( TreeNode* root, int k , int &visited, int &ksmall){
    if(!root || visited>=k) return;

    solve(root->left, k, visited, ksmall);
    visited++;
    if(visited==k){
        ksmall= root->val;
        return;
    }
    solve(root->right, k, visited, ksmall);
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int visited=0;
        int ksmall=-1;

        solve(root, k, visited, ksmall);
        return ksmall;
    }
};