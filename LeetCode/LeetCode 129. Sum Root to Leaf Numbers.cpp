// LeetCode 129. Sum Root to Leaf Numbers.cpp

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
    
    int FindSum(TreeNode *root, int n)
    {
        if(root->left == NULL && root->right == NULL)
        {
            n = (n * 10) + root->val;
            return n;
        }
            
        if(root == NULL)
            return 0;
        else
        {
            int leftSum = 0, rightSum = 0;
            if(root->left != NULL)
                leftSum = FindSum(root->left, n*10 + root->val);
            if(root->right != NULL)
                rightSum = FindSum(root->right, n*10 + root->val);
            
            return leftSum + rightSum;
        }
    }
    
    
    int sumNumbers(TreeNode* root) {
        
        
        if(root == NULL)
            return 0;

        return FindSum(root, 0);

    }
};