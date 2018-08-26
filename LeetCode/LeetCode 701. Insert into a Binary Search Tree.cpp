// LeetCode 701. Insert into a Binary Search Tree.cpp

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
    
    TreeNode *CreateNewNode(int value)
    {
        TreeNode *newNode = new TreeNode(value);
        
        return newNode;
    }
    
    
    
    TreeNode *Insert(TreeNode *root, int data)
    {
        if(root == NULL)
            root = CreateNewNode(data);
        else
        {
            if(data <= root->val)
                root->left = Insert(root->left, data);
            else
                root->right = Insert(root->right, data);
        }

        return root;
    }

    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
           
        return Insert(root, val);

    }
    
};