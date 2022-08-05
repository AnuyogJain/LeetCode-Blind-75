class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size () != t.size())
            return false;
        
        vector<int> temp(26);
        
        for (int i = 0; i < s.size(); i++) {
            temp[s[i] - 'a']++;
        }
        
        for (int i = 0; i < t.size(); i++) {
            temp[t[i] - 'a']--;
            if (temp[t[i] - 'a'] < 0)
                return false;
        }
        
        return true;
    }
};
