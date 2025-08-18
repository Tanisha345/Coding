class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n= arr.size();
        int i=1;
        int ans=0;
        while(i<n){
            while(i<n && arr[i]==arr[i-1]){
                i++;
            }

            int up=0;
            while(i<n && arr[i]>arr[i-1]){
                up++;
                i++;
            }

            int down=0;
            while(i<n && arr[i]<arr[i-1]){
                down++;
                i++;
            }

            if(up>0 && down>0){
                ans= max(ans, up+down+1);
            }
            
        }

        return ans;
    }
};