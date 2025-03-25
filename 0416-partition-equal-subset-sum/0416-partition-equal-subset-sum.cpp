bool solve(int n, vector<int> &nums, int sum, vector<vector<int>> &dp){
     if(sum==0) return true;
     if(n<0) return false;
     if(n==0)
     return (nums[0]== sum || sum==0);

     if(dp[n][sum]!=-1) return dp[n][sum];
     bool take= false;
     if(sum>= nums[n])   take= solve(n-1, nums, sum-nums[n], dp);
     bool nottake= solve(n-1, nums, sum, dp);

     return dp[n][sum]=take || nottake;
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target= sum/2;
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return solve(n-1, nums, target, dp);

    }
};