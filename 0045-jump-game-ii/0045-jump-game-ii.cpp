class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        int i=0;
        while(i<n){
            int maxJump= nums[i];
            if(i==n-1) return ans;
            if(i+maxJump >=n-1) return ans+1;
            if(nums[i]==0) return -1;
            
            
            int nextjumpind=i, nextjump=0;
            for(int j=i+1;j<=i+maxJump && j<n;j++){
                if(j+nums[j]>=nextjump)
                {
                    nextjump= j+nums[j];
                    nextjumpind=j;
                }
            }

            ans++;
            i=nextjumpind;
        }
        return -1;
    }
};