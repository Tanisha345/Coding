class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> visited(n, 0);
        vector<int> color(n, -1);
        
        for(int i=0;i<n;i++){
            if(visited[i]==0){
  queue<pair<int, int>> q;
        q.push({i, 0});
        visited[i]=1;


        while(!q.empty()){
            auto [node, c]= q.front();
            q.pop();

            for(auto it: graph[node]){
                if(visited[it]==0){
                    visited[it]=1;
                    color[it]= !c;
                    q.push({it, color[it]});
                }

                else if(color[it]==c)
                return false;

                
            }
        }
            }
        }
      
        return true;
    }
};