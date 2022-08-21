class Solution {
public:
    bool dfs(vector<vector<char>> &board, int i, int j, string word, int index) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[index] != board[i][j])
            return false;
        
        if (index == word.size() - 1)
            return true;
        
        char temp = board[i][j];
        board[i][j] = '.';
        
        if (dfs(board, i + 1, j, word, index + 1))
            return true;
        if (dfs(board, i, j + 1, word, index + 1))
            return true;
        if (dfs(board, i - 1, j, word, index + 1))
            return true;
        if (dfs(board, i, j - 1, word, index + 1))
            return true;
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0])
                    if (dfs(board, i, j, word, 0))
                        return true;
            }
        }
        
        return false;
    }
};
