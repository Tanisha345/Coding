// int solve(int house, int lasthouse, vector<int> &nums, vector<int> &dp){
//     if(house<lasthouse) return 0;
//     if(dp[house]!=-1) return dp[house];
//     int take= nums[house]+ solve(house-2, lasthouse, nums, dp);
//     int nottake= solve(house-1, lasthouse, nums, dp);
//     return dp[house]=max(take, nottake);
// }

int solve(vector<int> &nums){
    int n=nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    if(n==2) return max(nums[0], nums[1]);
    vector<int> dp(n, -1);
    dp[0]=nums[0];
    dp[1]=max(nums[0], nums[1]);
    for(int i=2;i<n;i++){
        dp[i]= max(dp[i-1], dp[i-2]+nums[i]);
    }

    return dp[n-1];
}


class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp1;
        vector<int> temp2;

        if(n==1) return nums[0];
        for(int i=0;i<n-1;i++){
            temp1.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            temp2.push_back(nums[i]);
        }

        int a= solve(temp1);
        int b= solve(temp2);
        return max(a,b);
    }
};