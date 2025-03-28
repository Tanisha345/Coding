class Solution {
public:
    bool canJump(vector<int>& nums) {
     int n= nums.size();
     int i=0;

     while(i<n){
        int maxJump=nums[i];
        if(i==n-1) return true;
        if(nums[i]==0) return false;
        int nextmax=0, nextval=0;
        for(int j=i+1;j<=i+maxJump && j<n;j++){
            if(j+nums[j]>=nextval){
                nextval=j+nums[j];
                nextmax=j;
            }
        }

        i=nextmax;
     }

     return true;   
    }
};