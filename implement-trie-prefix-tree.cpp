struct TrieNode {
    //children store Node to characters and isEnd stores if character is end of words or not
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            //if character exist move pointer to next else add a new node
            curr = word[i] - 'a';
            
            if (node->children[curr]) {
                node = node->children[curr];
            }
            else {
                node->children[curr] = new TrieNode();
                node = node->children[curr];
            }
        }
        
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            
            if (node->children[curr]) 
                node = node->children[curr];
            else 
                return false;
        }
        
        if (node->isEnd)
            return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < prefix.size(); i++) {
            curr = prefix[i] - 'a';
            
            if (node->children[curr])
                node = node->children[curr];
            else 
                return false;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
