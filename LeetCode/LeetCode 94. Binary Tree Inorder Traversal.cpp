// LeetCode 94. Binary Tree Inorder Traversal.cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
class Solution {
public:
    
    vector<int> ans;
    
    void InOrder(TreeNode *root)
    {
        if(root == NULL)
            return;
        
        InOrder(root->left);
        ans.push_back(root->val);
        InOrder(root->right);
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        InOrder(root);
        
        return ans;
    }
};