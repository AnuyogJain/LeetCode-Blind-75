class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int prefix = 1;
        int suffix = 1;
        
        //[{},{1},{1,2},{1,2,3}]
        //[{2,3,4},{3,4},{4},{}]
        //--------------------------------
        //[{2,3,4},{1,3,4},{1,2,4},{1,2,3}]
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        
        return ans;
    }
};
