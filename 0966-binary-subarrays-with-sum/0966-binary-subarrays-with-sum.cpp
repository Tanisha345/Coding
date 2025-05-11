int func(vector<int>& nums, int goal){
    int n=nums.size();
    int i=0;
    int sum=0;
    int ans=0;

    for(int j=0;j<n;j++){
        sum+=nums[j];
        while(i<=j && sum>goal){
            sum-=nums[i];
            i++;
        }
        ans+=(j-i+1);
    }
    return ans;
}


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums, goal)-func(nums, goal-1);
    }
};