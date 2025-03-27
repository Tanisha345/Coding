class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        int elem= nums[0];
        int count=0;
        for(int i=0;i<n;i++){
            if(count==0) elem= nums[i];
            if(nums[i]==elem){
                count++;
            }
            else{
                count--;
            }
        }
        return elem;
    }
};