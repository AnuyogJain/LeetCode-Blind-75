class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int productLeft = 1;
        int productRight = 1;
        int ans = nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            productLeft *= nums[i];
            productRight *= nums[nums.size() - i - 1];
            
            ans = max(ans, productLeft);
            ans = max(ans, productRight);
            
            if (productLeft == 0)
                productLeft = 1;
            
            if (productRight == 0)
                productRight = 1;
        }
        
        return ans;
    }
};
