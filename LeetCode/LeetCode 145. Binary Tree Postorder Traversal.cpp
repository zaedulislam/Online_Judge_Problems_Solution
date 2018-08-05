// LeetCode 145. Binary Tree Postorder Traversal.cpp

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
    
    void PostOrder(TreeNode *root)
    {
        if(root == NULL)
            return;
        
        PostOrder(root->left);
        PostOrder(root->right);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        PostOrder(root);
        
        return ans;
    }
};