int solve(int n, vector<int> &nums, vector<int> &dp){
    if(n<0) return 0;

    if(dp[n]!=-1) return dp[n];
    int take= nums[n]+ solve(n-2, nums, dp);
    int nottake= solve(n-1, nums, dp);

    return dp[n]=max(take, nottake);
}


class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);
        dp[0]=nums[0];
        if(n>1)
        dp[1]=max(nums[0], nums[1]);

        for(int i=2;i<n;i++){
            int take= nums[i]+dp[i-2];
            int nottake=dp[i-1];
            dp[i]= max(take, nottake);
        }
        return dp[n-1];
    }
};