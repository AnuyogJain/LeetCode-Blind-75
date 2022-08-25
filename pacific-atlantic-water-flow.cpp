class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &oceanToLand) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || oceanToLand[i][j] == true)
            return;
        
        oceanToLand[i][j] = true;
        int temp = heights[i][j];
        
        if (i - 1 >= 0 && heights[i - 1][j] >= temp)
            dfs(i - 1, j, heights, oceanToLand);
        
        if (j - 1 >= 0 && heights[i][j - 1] >= temp)
            dfs(i, j - 1, heights, oceanToLand);
        
        if (i + 1 < heights.size() && heights[i + 1][j] >= temp)
            dfs(i + 1, j, heights, oceanToLand);
        
        if (j + 1 < heights[0].size() && heights[i][j + 1] >= temp)
            dfs(i, j + 1, heights, oceanToLand);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> pacific(rows, vector<bool>(cols));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols));
        
        //to find oceanToLand for first and last row
        for (int i = 0; i < cols; i++) {
            dfs(0, i, heights, pacific);
            dfs(rows - 1, i, heights, atlantic);
        }
        
        //to find oceanToLand for first and last col
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, heights, pacific);
            dfs(i, cols - 1, heights, atlantic);
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};
