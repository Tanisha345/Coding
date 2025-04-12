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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* prev=NULL;
        
        if(!root) return new TreeNode(val);
        TreeNode* temp= root;

        while(temp){
            if(val<temp->val){
                prev= temp;
                temp=temp->left;
            }else if(val>temp->val){
                prev= temp;
                temp=temp->right;
            }
        }

        if(val< prev->val) prev->left= new TreeNode(val);
        else prev->right= new TreeNode(val);

        return root;
    }
};