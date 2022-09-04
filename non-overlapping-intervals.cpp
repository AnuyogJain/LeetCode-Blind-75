class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        vector<int> temp(2);
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (temp[1] > intervals[i][0]) {
                ans++;
                temp[1] = min(temp[1], intervals[i][1]);
            }
            else {
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }
        }
        
        return ans;
    }
};
