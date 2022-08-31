class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        
        for (int i = 0; i < amount + 1; i++)
            dp[0][i] = 1e5;
        
        for (int i = 0; i < coins.size() - 1; i++)
            dp[i][0] = 0;
        
        for (int i = 1; i < coins.size() + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (coins[i - 1] <= j) {
                    dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[coins.size()][amount] > 1e4 ? -1: dp[coins.size()][amount];
    }
};
