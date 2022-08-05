class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        
        for (int it: nums)
            s.insert(it);
        
        for (int it: s) {
            if (s.find(it - 1) == s.end()) {
                int temp = it + 1;
                int count = 1;
                
                while (s.find(temp++) != s.end()) {
                    count++;
                }
                
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
};
