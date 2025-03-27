class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int i=0;
        if(n==1) return 1;
        int j=1;

        while(i<n && j<n){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
            else
            j++;
        }

        return i+1;
    }
};