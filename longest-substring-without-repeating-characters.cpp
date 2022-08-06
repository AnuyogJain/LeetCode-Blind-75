class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        int i = 0;
        
        for (int j = 0; j < s.size(); j++) {
            //if character already exist we take move left window to its last occurance
            if (m.find(s[j]) != m.end()) {
                i = max(i, m[s[j]] + 1);
            }
            
            //calculating maximum window size
            ans = max(ans, j - i + 1);
            m[s[j]] = j;
        }
        
        return ans;
    }
};
