class Solution {
public:
    int findMin(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;
        int mid, ans=INT_MAX;

        while(low<=high){
            mid=(low+high)/2;

            if(arr[low]<=arr[high]){
                ans=min(ans, arr[low]);
                break;

            }

            else if(arr[low]<=arr[mid])
            {
                ans=min(ans, arr[low]);
                low=mid+1;
            }

            else{
                ans=min(ans, arr[mid]);

                high=mid-1;
            }
        }

        return ans;
    }
};