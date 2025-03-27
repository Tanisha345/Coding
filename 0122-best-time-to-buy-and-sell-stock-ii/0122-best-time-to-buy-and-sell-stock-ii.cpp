int solve(int i, int n, int sell, vector<int> &prices, vector<vector<int>> &dp){
    if(i>=n) return 0;
    if(dp[i][sell]!=-1) return dp[i][sell];

    if(sell==0){
        return dp[i][sell]=max(-prices[i]+ solve(i+1, n, 1, prices, dp), solve(i+1, n, 0, prices, dp));
    }else{
        return dp[i][sell]=max(prices[i]+ solve(i+1, n, 0, prices, dp), solve(i+1, n, 1, prices, dp));
    }
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        int prevbuy=0, prevsell=0;
        int currbuy=0, cursell=0;
        for(int i=n-1;i>=0;i--){
            currbuy=max(-prices[i]+ prevsell, prevbuy);
            cursell= max(prices[i]+prevbuy, prevsell);
            prevsell=cursell;
            prevbuy=currbuy;
        }

        return currbuy;
    }
};