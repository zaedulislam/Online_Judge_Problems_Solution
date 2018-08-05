// LeetCode 144. Binary Tree Preorder Traversal.cpp

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
    
    void PreOrder(TreeNode *root)
    {
        if(root == NULL)
            return;

        ans.push_back(root->val);
        PreOrder(root->left);
        PreOrder(root->right);

    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        ans.clear();   
        PreOrder(root);
        
        return ans;
    }
};

