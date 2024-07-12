int lower(int low, int high, vector<int> nums, int target){
    int mid, ans=high+1;

    while(low<=high){
        mid=(high+low)/2;

        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }

        else
        low=mid+1;
    }

    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=lower(0, nums.size()-1, nums, target);
        int b=lower(0, nums.size()-1, nums, target+1)-1;

        if(a>=0 && a<nums.size() && nums[a]==target)
        return {a, b};

        else return {-1, -1};
    }
};