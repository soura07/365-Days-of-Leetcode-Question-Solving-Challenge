class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxiProfit = 0;
        int BestProfitToBuy = prices[0];
        int n = prices.size();
        for(int i=0; i<n; i++){
            if(prices[i] > BestProfitToBuy){
                maxiProfit = max(maxiProfit, prices[i] - BestProfitToBuy);
            }
            BestProfitToBuy = min(BestProfitToBuy, prices[i]);
        }
        return maxiProfit;
    }
};