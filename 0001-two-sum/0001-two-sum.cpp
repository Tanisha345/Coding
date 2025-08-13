class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n= nums.size();
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            int diff= target - nums[i];
            if(mp[diff]){
                return {mp[diff]-1, i};
            }

            else{
                mp[nums[i]]=i+1;
            }
        }

        return {-1, -1};
    }
};