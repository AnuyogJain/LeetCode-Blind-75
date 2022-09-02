class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        
        for (int it: nums) {
            sum += it;
            
            ans = max(ans, sum);
            
            if (sum < 0)
                sum = 0;
        }
        
        return ans;
    }
};
