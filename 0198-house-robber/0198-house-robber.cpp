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
        if(n==0) return 0;
        int prev=nums[0];
        if(n==1) return prev;
        int sec=max(nums[0], nums[1]);
        if(n==2) return sec;
        int ans=0;
        for(int i=2;i<n;i++){
            int take= nums[i]+prev;
            int nottake=sec;
            ans= max(take, nottake);
            prev=sec;
            sec=ans;
        }
        return ans;
    }
};