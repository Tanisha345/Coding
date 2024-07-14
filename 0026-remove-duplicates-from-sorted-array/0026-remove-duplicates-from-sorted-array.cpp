class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i=1;
        int n=arr.size();

        for(int j=1;j<n;j++){
            if(arr[j]!=arr[j-1])
            {
                arr[i]=arr[j];
                i++;
            }

        }
        return i;
    }
};