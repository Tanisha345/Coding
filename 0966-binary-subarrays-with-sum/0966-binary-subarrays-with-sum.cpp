class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n= nums.size();
        int ans=0;
        int sum=0;
        int i=0;
        unordered_map<int, int> mp;
      for(int j=0;j<n;j++){
            sum+=nums[j];
            if(sum==goal) ans++;
            ans+=mp[sum-goal];
            mp[sum]++;
        }

        return ans;
    }
};