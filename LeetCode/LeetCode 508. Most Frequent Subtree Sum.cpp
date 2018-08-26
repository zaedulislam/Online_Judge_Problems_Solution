// LeetCode 508. Most Frequent Subtree Sum.cpp

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
    
    map<int, int> MAP;
    
    int Sum(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        else 
        {
            int L = 0, R = 0;
            L = Sum(root->left);
            R = Sum(root->right);
            
            MAP[L + R + root->val]++;
            
            return L + R + root->val;
        }
        
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        MAP.clear();
        
        int ret = Sum(root);
        
        int mx = 0;
        for(auto it = MAP.begin(); it != MAP.end(); it++)
        {
            if(it->second > mx)
                mx = it->second;
        }
        
        vector<int> ans;
        for(auto it = MAP.begin(); it != MAP.end(); it++)
        {
            if(it->second == mx)
                ans.push_back(it->first);
        }
        
        return ans;
    }
};