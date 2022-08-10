/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    
    void depth(TreeNode* root, int height) {
        if (!root) {
            ans = max(height, ans);
            return;
        }
        
        depth(root->left, height + 1);
        depth(root->right, height + 1);
    }
    
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        depth(root, 0);
        
        return ans;
    }
};
