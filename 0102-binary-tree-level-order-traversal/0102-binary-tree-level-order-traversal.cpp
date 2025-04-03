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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
       vector<pair<int, int>>  temp;
        queue<pair<TreeNode*, int>> q;
        int n=0;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, level]= q.front();
            q.pop();
            n=max(n, level);
            temp.push_back({node->val, level});

            if(node->left){
                q.push({node->left, level+1});
            }

            if(node->right){
                q.push({node->right, level+1});
            }


        }

   vector<vector<int>>  ans(n+1);
        for(auto it: temp){
            ans[it.second].push_back(it.first);
        }

        return ans;
    }
};