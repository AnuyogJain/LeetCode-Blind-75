class Solution {
public:
    void dfs(vector<int> candidates, vector<vector<int>> &ans, vector<int> temp, int target, int index) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if(index == candidates.size()) {
            return;
        }
        
        //include
        if (target - candidates[index] >= 0) {
            temp.push_back(candidates[index]);
            dfs(candidates, ans, temp, target - candidates[index], index);
            temp.pop_back();
        }
        
        //not include
        dfs(candidates, ans, temp, target, index + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        dfs(candidates, ans, temp, target, 0);
        
        return ans;
    }
};
