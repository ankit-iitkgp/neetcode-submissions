class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int local_min = prices[0];
        int local_max = prices[0];
        int profit = 0;
        if(prices.size()<2) return 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]<local_min) {
                local_min = prices[i];
                local_max = prices[i];
            }
            else if(prices[i]>local_max) {
                local_max = prices[i];
                profit = max(local_max - local_min, profit);
            }
        }
        return profit;
    }
};
