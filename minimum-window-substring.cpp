class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        string ans;
        int minStart = 0;
        int minLength = INT_MAX;
        int i = 0, j = 0;
        int counter = t.size();
        
        //mapping characters of string t
        for (char c: t)
            m[c]++;
        
        while (j < s.size()) {
            //if element exist in string t
            if (m[s[j]] > 0)
                counter--;
            
            m[s[j]]--;
            j++;
            
            //while every element of substring of s exist in t
            while (counter == 0) {
                if (j - i < minLength) {
                    //setting length and start
                    minLength = j - i;
                    minStart = i;
                }
                
                //if element exist in string t
                m[s[i]]++;
                if (m[s[i]] > 0)
                    counter++;
                
                i++;
            }
        }
        
        //base condition
        if (minLength == INT_MAX)
            return "";
        
        //making substring
        ans = s.substr(minStart, minLength);
        
        return ans;
    }
};
