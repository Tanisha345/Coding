class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int zero=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero=i;
                break;
            }
        }
        if(zero==-1) return;

       int k=zero+1;
       while(k<n && zero<n){
        while(nums[zero]!=0 && zero<n){
            zero++;
        }
        if(nums[k]==0){
            k++;
        }
        else if(nums[k]!=0){
            swap(nums[zero], nums[k]);
        }

       }
        
    }
};