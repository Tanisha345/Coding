class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int mid;


        while(low<=high){
            mid=(low+high)/2;

             if(nums[mid]==target)
            return true;


            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }

           

            else if(nums[low]<=nums[mid]){

                if(target>=nums[low] && target< nums[mid])
                high=mid-1;

                else
                low=mid+1;
            }


            else{
                if(target>nums[mid] and target<=nums[high])
                low=mid+1;

                else
                high=mid-1;
            }
        }

        return false;
    }
};