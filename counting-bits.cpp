class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        int multiply = 1;
        
        for (int i = 1; i < n + 1; i++) {
            if (multiply * 2 == i)
                multiply = i;
            dp[i] = dp[i - multiply] + 1;
        }
        
        return dp;
    }
};
