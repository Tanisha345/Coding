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

int height(TreeNode* root)
{
    if(!root) return 0;

    int left= height(root->left);
    if(left==-1) return left;
    int right= height(root->right);

    if(right==-1) return right;

    if(abs(left-right)>1) return -1;

    return 1+max(left, right);

}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(height(root)==-1)  return false;
        return true;    }
};