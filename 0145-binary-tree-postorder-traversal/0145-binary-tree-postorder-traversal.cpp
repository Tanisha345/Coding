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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root==NULL)
        return ans;


        while(root!=NULL){
            if(root->right==NULL){
             ans.push_back(root->val);
             root=root->left;
            }


            else{
                TreeNode* prev=root->right;

                while(prev->left && prev->left!=root)
                prev=prev->left;


                if(prev->left==NULL){
                    ans.push_back(root->val);
                    prev->left=root;
                    root=root->right;
                }

                else{
                    prev->left=NULL;
                    root=root->left;
                }
            }



        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};