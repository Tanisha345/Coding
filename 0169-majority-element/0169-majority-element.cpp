class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n=nums.size();
       int count=0;

       int index=0;

       for(int i=0;i<n;i++){
        if(nums[i]==nums[index]){
            count++;
        }

        else{
            count--;
        }

        if(count==0)
        {
            index=i+1;
        }
       }

       return nums[index];
    }

};