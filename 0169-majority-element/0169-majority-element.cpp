class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        int candidate= nums[0];
        int votes=0;
        for(int i=0;i<n;i++){
            if(nums[i]== candidate) {
                votes++;
            }

            else if(votes==0){
                candidate= nums[i];
                votes++;
            }else{
                votes--;
            }
        }
        return candidate;
    }
};