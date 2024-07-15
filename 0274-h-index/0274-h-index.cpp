bool isvalid(vector<int> &citations, int mid){

    int count=0;
    for(int i=0;i<citations.size();i++){
        if(citations[i]>=mid){
            count++;
        }

    }

    if(count>=mid) return true;
    return false;
}

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(), citations.end());

        int low=0;
        int high=n;
        int ans=1;
        while(low<=high){
           int mid=(low+high)/2;

            if(isvalid(citations, mid))
            {
                ans=mid;
                low=mid+1;
            }

            else{
                high=mid-1;
            }
        }

        return ans;
    }
};