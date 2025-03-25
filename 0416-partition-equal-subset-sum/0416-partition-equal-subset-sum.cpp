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

        vector<int> dp1(target+1, 0);
        vector<int> dp2(target+1, 0);

        dp1[0]=1;

        if(nums[0]<=target){
            dp1[nums[0]]= 1;
        }


        for(int i=1;i<n;i++){
            dp2[0]=1;
            for(int j=1;j<=target;j++){
                if(j>=nums[i])
                dp2[j]= dp1[j-nums[i]] || dp1[j];
                else
                dp2[j]= dp1[j];
            }
            dp1=dp2;
        }
        return dp1[target];

    }
};