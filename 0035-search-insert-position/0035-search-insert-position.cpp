int lower(int l, int h, vector<int> &nums, int target)
{
    int ans=h+1;
    int mid;

    while(l<=h){
        mid=(l+h)/2;

        if(nums[mid]>=target){
            ans=mid;
            h=mid-1;
        }

        else
        l=mid+1;
    }

    return ans;
}
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=lower(0, nums.size()-1, nums, target);
        return ans;
    }
};