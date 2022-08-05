class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        if (nums.size() < 3)
            return ans;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) { 
                int j = i + 1;
                int k = nums.size() - 1;
                int num = nums[i] * -1;

                while (j < k) {
                    if (nums[j] + nums[k] == num) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        
                        while (j < k && nums[j] == nums[j + 1])
                            j++;
                    
                        while (j < k && nums[k] == nums[k - 1])
                            k--;
                        
                        j++;
                        k--;
                    }
                    else if (nums[j] + nums[k] > num) {
                        k--;
                    }
                    else j++;
                }
            }
        }
        
        return ans;
    }
};
