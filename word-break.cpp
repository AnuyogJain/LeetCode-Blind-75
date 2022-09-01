class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = 0; j < wordDict.size(); j++) {
                //for every index check if word exist in wordDict
                if (i + wordDict[j].size() <= s.size() && s.substr(i, wordDict[j].size()) == wordDict[j]) {
                    //if exist set value to dp[i + size of word]
                    dp[i] = dp[i + wordDict[j].size()];
                }
                if (dp[i])
                    break;
            }
        }
        
        return dp[0];
    }
};
