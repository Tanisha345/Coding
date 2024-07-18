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




TreeNode* solve(TreeNode* root){
    TreeNode* ltemp=root->left;
    TreeNode* rtemp=root->right;

    if(ltemp==NULL) return rtemp;
    else if(rtemp==NULL) return ltemp;

    TreeNode* trav=rtemp;

    while(trav->left!=NULL){
        trav=trav->left;
    }

    trav->left=ltemp;
    return rtemp;
}
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        TreeNode* temp=root;



        if(temp->val==key){
            root=solve(temp);
            return root;
        }


while(temp!=NULL){
        if(key<temp->val){
            if(temp->left!=NULL && temp->left->val==key){
               temp->left=solve(temp->left);
               return root;
            }

            else{
                temp=temp->left;
            }
        }

        else if( key>temp->val){
            if(temp->right && temp->right->val==key){
                temp->right=solve(temp->right);
                return root;
            }

            else{
                temp=temp->right;
            }
        }

}
      return root;
       
    }
};