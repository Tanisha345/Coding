class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int currStock=n-1;
        int profit= 0;
        for(int i=n-2;i>=0;i--){
            if(prices[currStock]>prices[i]){
                profit= max(profit, prices[currStock]- prices[i]);
            }else{
                currStock=i;
            }
        }
        return profit;
    }
};