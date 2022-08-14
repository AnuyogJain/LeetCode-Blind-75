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
    int ans = INT_MIN;
    
    int pathSum(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        
        //ignoring the path with negative sum
        int leftSum = max(0, pathSum(root->left, sum));
        int rightSum = max(0, pathSum(root->right, sum));
        
        //taking sum with both split
        int path = leftSum + rightSum + root->val;
    
        //calculating maximum sum
        ans = max(ans, path);
        
        //only one path can be taken from parent node so max of leftSum and rightSum is returned
        return root->val + max(leftSum, rightSum);
        
    }
    
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int sum = 0;
        
        pathSum(root, sum);
        
        return ans;
    }
};
