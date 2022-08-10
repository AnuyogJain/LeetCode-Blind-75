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
    bool sameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        
        if (!p || !q)
            return false;
        
        if (p->val != q->val)
            return false;
        
        return sameTree(p->left, q->left) && sameTree(p->right, q->right);
    }
    
    void inorder(TreeNode* root, TreeNode* subRoot, bool &ans) {
        if (!root)
            return;
        
        if (root->val == subRoot->val) {
            if (sameTree(root, subRoot))
                ans = true;
        }
        
        inorder(root->left, subRoot, ans);
        inorder(root->right, subRoot, ans);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        
        bool ans = false;
        inorder(root, subRoot, ans);
        
        return ans;
    }
};
