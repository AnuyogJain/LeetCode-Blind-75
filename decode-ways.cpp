class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        
        vector<int> dp(s.size() + 1);
        
        //empty and single character string will have 1 possible answer
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= s.size(); i++) {
            //a number can be selected two ways either a single digit or two digits 
            //as mapping is between 1 to 26
            int singleDigit = stoi(s.substr(i - 1, 1));
            int doubleDigit = stoi(s.substr(i - 2, 2));
            
            //single digit number must be greater than 0
            if (singleDigit >= 1)
                dp[i] += dp[i - 1];
            
            //double digit number must be between 10 to 26
            if (doubleDigit >= 10 && doubleDigit <= 26)
                dp[i] += dp[i - 2];
        }
        
        return dp[s.size()];
    }
};
