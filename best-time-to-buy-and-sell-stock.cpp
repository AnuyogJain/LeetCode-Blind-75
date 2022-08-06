class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = prices[0];
        int ans = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            currMin = min(currMin, prices[i]);
            ans = max(ans, prices[i] - currMin);
        }
        
        return ans;
    }
};
