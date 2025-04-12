/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";

        string ans="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();

            if(node==NULL) {
                ans+="N$";
                continue;
            }
            else
            ans+=to_string(node->val)+"$";
            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.length()==0) return NULL;

       stringstream ss(data);
       string str;
       getline(ss, str, '$');
       if(str=="N") return NULL;
       TreeNode* root= new TreeNode(stoi(str));

       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
        TreeNode* node= q.front();
        q.pop();
        getline(ss, str, '$');

        if(str=="N")
        {
            node->left=NULL;
        }else{
            node->left= new TreeNode(stoi(str));
            q.push(node->left);
        }

        getline(ss, str, '$');
        if(str=="N"){
            node->right=NULL;
        }else{
            node->right= new TreeNode(stoi(str));
            q.push(node->right);
        }

       }

       return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));