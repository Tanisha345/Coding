int func(vector<int> &nums, int k){
    int n= nums.size();
    int i=0, ans=0, sum=0;

    for(int j=0;j<n;j++){
        sum+=nums[j];
        while(i<=j && sum>k){
            sum-=nums[i];
            i++;
        }

        ans+=(j-i+1);
    }
    return ans;
}

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }


        return func(nums, k)- func(nums, k-1); 
    }
};