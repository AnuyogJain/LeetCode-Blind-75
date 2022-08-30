class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int i = 0;
        
        while (i < s.size()) {
            int j = i;
            int k = i;
            
            while (k + 1 < s.size() && s[k] == s[k + 1]) {
                k++;
            }
            
            while (j - 1 >= 0 && k + 1 < s.size() && s[j - 1] == s[k + 1]) {
                j--;
                k++;
            }
            
            int len = k - j + 1;
            string temp = s.substr(j, len);
            
            if (temp.size() > ans.size())
                ans = temp;
            
            i++;
        }
        
        return ans;
    }
};
