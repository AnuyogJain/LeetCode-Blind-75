class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            //corner case
            if(st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
                return false;
            
            if (s[i] == '('  || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            
            else if (s[i] == ')' && st.top() == '('  || s[i] == '}' && st.top() == '{' || s[i] == ']' && st.top() == '[')
                st.pop();
            
            else 
                return false;
        }
        
        return st.empty();
    }
};
