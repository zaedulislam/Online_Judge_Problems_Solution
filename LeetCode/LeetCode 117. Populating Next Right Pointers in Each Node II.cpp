// LeetCode 117. Populating Next Right Pointers in Each Node II.cpp

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        if(root == NULL)
            return;
        
        queue<TreeLinkNode*> Q;
        
        Q.push(root);
        Q.push(NULL);
        
        while(!Q.empty())
        {
            TreeLinkNode *curr = Q.front();
            Q.pop();
            
            if(curr != NULL)
            {
                curr->next = Q.front();
                
                if(curr->left != NULL)
                    Q.push(curr->left);
                if(curr->right != NULL)
                    Q.push(curr->right);
                
            }
            else
            {
                if(!Q.empty())
                    Q.push(NULL);
            }
            
            
        }
    
        
    }
};