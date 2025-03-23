int solve(int house, int lasthouse, vector<int> &nums, vector<int> &dp){
    if(house<lasthouse) return 0;
    if(dp[house]!=-1) return dp[house];
    int take= nums[house]+ solve(house-2, lasthouse, nums, dp);
    int nottake= solve(house-1, lasthouse, nums, dp);
    return dp[house]=max(take, nottake);
}


class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int a= solve(n-1, 1, nums, dp1);
        int b= solve(n-2, 0, nums, dp2);
        return max(a,b);
    }
};