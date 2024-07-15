class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int ci=0;
        

        while(ci<n){
            int maxjump=ci+nums[ci];

            if(maxjump>=n-1)
            return true;

            int ni=ci;
            int nmax=INT_MIN;
            for(int i=ci;i<=maxjump;i++){

                int x=i+nums[i];
                if(x> nmax){
                    nmax=x;
                    ni=i;
                }
            }

            if(ni==ci) return false;
            ci=ni;
        }

        return true;

    }
};