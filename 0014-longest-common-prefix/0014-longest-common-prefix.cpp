class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int tem=strs[i].length();
             mini=min(tem, mini);
        }

        if(mini==INT_MAX) return ans;
        int i=0;
        while(i<mini){
            bool same=true;
            char temp=strs[0][i];
            for(int k=1;k<n;k++){
                if(strs[k][i]!=temp)
                same=false;
            }

            if(same){
                ans+=temp;
            }

            else{
                return ans;
            }
            i++;
        }
        return ans;
    }
};