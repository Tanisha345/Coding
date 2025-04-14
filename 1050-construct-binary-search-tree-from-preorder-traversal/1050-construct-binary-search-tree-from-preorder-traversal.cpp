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

TreeNode* solve(int left, int right, vector<int> & preorder){

    if(left>right) return NULL;

    TreeNode* root= new TreeNode(preorder[left]);
    int index=left+1;
    while(index<=right && preorder[index]<preorder[left])
    index++;
    root->left= solve(left+1, index-1, preorder);
    root->right= solve(index, right, preorder);
    return root;
}
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        int left=0;
        int right= preorder.size()-1;

        return solve(left, right, preorder);
    }
};