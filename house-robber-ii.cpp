class Solution {
public:
    int solve(vector<int> nums) {
        int n = nums.size();
        int dp[n + 1];
        
        dp[0] = 0;
        dp[1] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
        }
        
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        vector<int> arr1;
        vector<int> arr2;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0)
                arr1.push_back(nums[i]);
            if (i != nums.size() - 1)
                arr2.push_back(nums[i]);
        }
        
        //solve house robber I without first element and without last element
        int noFirst = solve(arr1);
        int noLast = solve(arr2);
        
        return max(noFirst, noLast);
    }
};
