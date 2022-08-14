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
    TreeNode* build(vector<int> preorder, vector<int> inorder, int &index, int start, int end) {
        if (start > end)
            return NULL;
        
        TreeNode* node = new TreeNode(preorder[index]);
        
        int mid = 0;
        
        //find index of preorder[index] in inorder
        for (int i = 0; i < preorder.size(); i++) {
            if (inorder[i] == preorder[index]) {
                mid = i;
                break;
            }
        }
        
        index++;
        
        //break left side from start to mid - 1
        node->left = build(preorder, inorder, index, start, mid - 1);
        
        //break right side form mid + 1 to end
        node->right = build(preorder, inorder, index, mid + 1, end);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
};
