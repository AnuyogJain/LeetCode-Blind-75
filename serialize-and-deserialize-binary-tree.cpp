/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serial(TreeNode* root, string &ans) {
        if (!root) {
            ans += "N/";
            return;
        }
        
        ans += to_string(root->val);
        ans += '/';
        serial(root->left, ans);
        serial(root->right, ans);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        serial(root, ans);
        return ans;
    }
    
    TreeNode* deserial(string s, int &index) {
        if (index >= s.size()) {
            return NULL;
        }
        
        if (s[index] == 'N') {
            index += 2;
            return NULL;
        }
        
        string temp = "";
        while (s[index] != '/') {
            temp += s[index++];
        }
        index++;
        int val = stoi(temp);
        
        TreeNode* node = new TreeNode(val);
        
        node->left = deserial(s, index);
        node->right = deserial(s, index);
        
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        int index = 0;
        root = deserial(data, index);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
