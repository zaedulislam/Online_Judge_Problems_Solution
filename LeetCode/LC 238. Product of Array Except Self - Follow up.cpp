// LeetCode 238. Product of Array Except Self.cpp


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int I, product = 1;
        vector<int> ans;
        
        for(I = 0; I < nums.size(); I++)
        {
            ans.push_back(product);
            product *= nums[I];
        }
        
        product = 1;
        for(I = nums.size() - 1; I >= 0; I--)
        {
            ans[I] *= product;
            product *= nums[I];
        }
        
        return ans;
        
    }
};
