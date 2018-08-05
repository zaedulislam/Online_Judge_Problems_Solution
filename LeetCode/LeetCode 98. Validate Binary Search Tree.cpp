// LeetCode 98. Validate Binary Search Tree.cpp

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
    
    bool isValidBST(TreeNode* root) {
           
        InOrder(root);
        
        bool ok = true;
        
        int I, SZ = ans.size();
        if(SZ > 1)
        {
            for(I = 1; I < SZ; I++)
            {
                if(ans[I - 1] >= ans[I])
                {
                    ok = false;
                    break;
                }
            }
        }
        
        return ok;
        
    }
};