class Solution {
public:
    //calculating number of palindromes
    int count(string s, int left, int right) {
        int palindromes = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            palindromes++;
            left--;
            right++;
        }
        
        return palindromes;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        
        for (int i = 0; i < s.size(); i++) {
            //for odd length palindromes
            ans += count(s, i, i);
            
            //for even length palindromes
            ans += count(s, i, i + 1);
        }
        
        return ans;
    }
};
