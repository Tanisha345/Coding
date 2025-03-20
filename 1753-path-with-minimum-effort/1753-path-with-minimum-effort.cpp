class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();

        int ans=0;
         vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto [effort, coords]=pq.top();
            pq.pop();
            int i=coords.first;
            int j= coords.second;

            if(i==n-1 && j==m-1) return effort;

            int x[4]={-1, 1, 0, 0};
            int y[4]={0, 0, 1, -1};

            for(int k=0;k<4;k++){
                int newx= i+x[k];
                int newy= j+y[k];

                if(newx>=0 && newx<n && newy>=0 && newy<m ){
                    int newEffort = max(effort, abs(heights[i][j] - heights[newx][newy]));
                    if(newEffort < dist[newx][newy]) {
                     dist[newx][newy]=newEffort;
                    pq.push({newEffort, {newx, newy}});
                    }
                }
            }
        }
        return -1;
    }
};