/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        int count = 0;
        int ans = 0;
        int i = 0;
        int j = 0;
        vector<int> start;
        vector<int> end;

        for (int i = 0; i < intervals.size(); i++) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        while (i < intervals.size()) {
            if (start[i] < end[j]) {
                i++;
                count++;
                ans = max(count, ans);
            }
            else {
                j++;
                count--;
            }
        }

        return ans;
    }
};
