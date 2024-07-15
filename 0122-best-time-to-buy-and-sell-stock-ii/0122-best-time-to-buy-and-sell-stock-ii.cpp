// int solve(int i, int buy, vector<int> &prices){
//     if(i==prices.size())
//     return 0;

//     int take=0;
//     int nottake=0;
//     if(buy){
//      take=-prices[i]+solve(i+1, 0, prices);
//      nottake=solve(i+1, 1, prices);
//     }

//     else{
//         take=prices[i]+solve(i+1, 1, prices);
//         nottake=solve(i+1, 0, prices);
//     }

//     return max(take, nottake);
// }

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // int n=prices.size();
        // vector<vector<int>>  dp(n+1, vector<int> (2, 0));

        // for(int i=n-1;i>=0;i--){
        //     dp[i][1]=max(-prices[i]+dp[i+1][0], dp[i+1][1]);
        //     dp[i][0]=max(prices[i]+ dp[i+1][1], dp[i+1][0]);
        // }
        // return dp[0][1];

        int start=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(start<prices[i])
            profit+=prices[i]-start;

            start=prices[i];

        }

        return profit;
    }
};