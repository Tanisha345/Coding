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

    int left= 1+height(root->left);
    int right= 1+height(root->right);

    return max(left, right);
    return abs(left-right);

}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int lefth= height(root->left);
        int righth= height(root->right);

        if(abs(lefth-righth)> 1) return false;
        
        bool l=isBalanced(root->left);
        bool r=isBalanced(root->right);

        

        return l && r;
    }
};