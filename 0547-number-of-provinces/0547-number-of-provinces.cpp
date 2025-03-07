void make_adj(int v, vector<vector<int>> &adj, vector<vector<int>> &isConnected){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

// void bfs(int i, vector<int> &visited, vector<vector<int>> &adj){
//     queue<int> q;
//     q.push(i);
//     visited[i]=1;

//     while(!q.empty()){
//         int node=q.front();
//         q.pop();

//         for(auto it: adj[node]){
//             if(!visited[it]){
//                 visited[it]=1;
//                 q.push(it);
//             }
//         }
//     }
// }


void dfs(int i, vector<int> &visited, vector<vector<int>> &adj){
if(visited[i])
return;
visited[i] =1;
for(auto it: adj[i]){
    dfs(it, visited, adj);
}
}
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v= isConnected.size();
        vector<vector<int>> adj(v);
        vector<int> visited(v, 0);
        make_adj(v,adj, isConnected);
int count=0;
        for(int i=0;i<v;i++){
            if(visited[i]==0){
               count++;
                // bfs(i, visited, adj);

                dfs(i, visited, adj);
            }
        }

        return count;
    }
};