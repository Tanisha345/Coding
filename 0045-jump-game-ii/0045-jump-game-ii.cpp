class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ci=0;

        if(n==1) return 0;
        int jumps=0, maxjump;

        while(ci<n){
            maxjump=ci+nums[ci];
            if(maxjump>=n-1) return jumps+1;

            int ni=ci;
            int nmax=INT_MIN;

            for(int i=ci; i<=maxjump;i++){
                int x=i+nums[i];
                if(x>nmax){
                    nmax=x;
                    ni=i;
                }
            }

            if(ni==ci) return -1;
            ci=ni;
            jumps++;
        }

        return jumps;
    }
};