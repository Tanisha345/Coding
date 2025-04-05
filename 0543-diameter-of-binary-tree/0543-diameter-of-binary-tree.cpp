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

int solve(TreeNode* root, int &ans){
    if(!root) return 0;

    int left= solve(root->left, ans);
    int right= solve(root->right, ans);

    ans= max(ans, 1+left+right);
    return 1+ max(left, right);
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        solve(root, ans);

        return ans==INT_MIN? 0 : ans-1;
    }
};