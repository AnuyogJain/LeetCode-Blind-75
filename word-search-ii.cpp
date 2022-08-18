class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        
        isWord = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string s) {
        TrieNode* node = root;
        int index;
        
        for (int i = 0; i < s.size(); i++) {
            index = s[i] - 'a';
            
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            
            node = node->children[index];
        }
        
        node->isWord = true;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, string s, TrieNode* node, vector<string> &ans) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.') {
            return;
        }
        
        char temp = board[i][j];
        
        node = node->children[temp - 'a'];
        
        if (!node)
            return;
        
        s += board[i][j];
        
        if (node->isWord) {
            ans.push_back(s);
            node->isWord = false;
        }
        
        board[i][j] = '.';
        
        dfs(board, i + 1, j, s, node, ans);
        dfs(board, i - 1, j, s, node, ans);
        dfs(board, i, j + 1, s, node, ans);
        dfs(board, i, j - 1, s, node, ans);
        
        board[i][j] = temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //insert all words in Trie
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }
        
        vector<string> ans;
        TrieNode* node = root;
        
        //find every word that can be formed from board and search in Trie
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, "", node, ans);
            }
        }
        
        return ans;
    }
};
