class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp(2);
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (temp[1] >= intervals[i][0]) {
                temp[1] = max(temp[1], intervals[i][1]);
            }
            else {
                ans.push_back({temp[0], temp[1]});
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }
        }
        ans.push_back({temp[0], temp[1]});
        
        return ans;
    }
};
