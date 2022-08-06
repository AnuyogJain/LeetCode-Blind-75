class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int ans = 0;
        int i = 0;
        
        for (int j = 0; j < s.size(); j++) {
            int maxEle = 0;
            m[s[j]]++;
            
            //finding the maximum frequency element present in the window
            for (auto it: m)
                maxEle = max(maxEle, it.second);
            
            //if replacement elements (window size - max freq ele) is more than k
            //keep increasing the left window
            while ((j - i + 1) - maxEle > k) {
                m[s[i]]--;
                i++;
            }
            
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};
