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
    //setting left and right boundaries
    //root values must be greater than left and less than right
    bool valid(TreeNode* root, long left, long right) {
        if (!root)
            return true;
        
        if (root->val <= left || root->val >= right)
            return false;
        
        //for left node, left boundary is left and right boudary is root value
        //for right node, left boundary is root value and right boudary is right
        return valid(root->left, left, root->val) && valid(root->right, root->val, right);
    }
    
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};
