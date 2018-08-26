// LeetCode 513. Find Bottom Left Tree Value.cpp

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
    int findBottomLeftValue(TreeNode* root) {
            

        queue<TreeNode*> Q;
        vector<TreeNode*> nodePtr;
        
        Q.push(root);
        int ans = root->val;
        
        while(!Q.empty())
        {
            
            while(!Q.empty())
            {
                TreeNode *curr = Q.front();
                Q.pop();
                
                TreeNode *L = curr->left;
                TreeNode *R = curr->right;
                
                if(L != NULL)
                    nodePtr.push_back(L);
                
                if(R != NULL)
                    nodePtr.push_back(R);
                
            }
            
            if(nodePtr.size() != 0)
            {
                for(int I = 0; I < nodePtr.size(); I++)
                    Q.push(nodePtr[I]);
                    
                ans = nodePtr[0]->val;
                nodePtr.clear();
            }
            
        }
        
        return ans;
        
    }
};