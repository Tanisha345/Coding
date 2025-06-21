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
        if(!root) return ans;

        stack<TreeNode*> s1;
        s1.push(root);

        while(!s1.empty()){
            TreeNode* t= s1.top();
            s1.pop();
            ans.emplace_back(t->val);

            if(t->left) s1.push(t->left);
            if(t->right) s1.push(t->right);
        }

         reverse(ans.begin(), ans.end());
         return ans;

    }
};