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

void insertNode(TreeNode* &root, int val)
{
    if(!root){
        root= new TreeNode(val);
        return;
    }

    TreeNode* temp= root;
    while(temp){
        if(val<temp->val)
        {
            if(temp->left) temp= temp->left;
            else{
                temp->left= new TreeNode(val);
                return;
            }
        }else{
            if(temp->right) temp=temp->right;
            else{
                temp->right= new TreeNode(val);
                return;
            }
        }

    }
    return;
}
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(int i=0;i<preorder.size();i++){
            insertNode(root, preorder[i]);
        }
        return root;
    }
};