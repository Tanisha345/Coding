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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        bool rev= false;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s= q.size();
            vector<int> temp;

            for(int i=0;i<s;i++){
                auto node= q.front();
                q.pop();
                temp.emplace_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(rev) reverse(temp.begin(), temp.end());
            rev=!rev;
            ans.emplace_back(temp);
        }
        return ans;
    }
};