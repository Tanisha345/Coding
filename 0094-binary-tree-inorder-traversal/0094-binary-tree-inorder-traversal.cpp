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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> st;
        TreeNode* temp=root;

        while(true){
            if(temp){
                st.push(temp);
                temp=temp->left;
            }else{
                if(st.empty()) break;
                TreeNode* t= st.top();
                st.pop();
                ans.emplace_back(t->val);
                temp=t->right;
            }
        }
        return ans;
    }
};