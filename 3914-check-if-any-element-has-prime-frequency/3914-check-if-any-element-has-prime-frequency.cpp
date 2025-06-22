
bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}

class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto it: mp){
            if(isPrime(it.second)){
                return true;
            }
        }

        return false;
    }
};