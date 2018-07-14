// LeetCode 53. Maximum Subarray.cpp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int I, n = nums.size(), currSum = 0, maxSum = 0;
        for(I = 0; I < n; I++)
        {
            currSum += nums[I];
            
            if(currSum < 0)
                currSum = 0;
            
            maxSum = max(maxSum, currSum);
        }
        
        
        if(maxSum == 0)
        {
            maxSum = (1 << 31) - 1;
            maxSum *= (-1);
            for(I = 0; I < n; I++)
                maxSum = max(maxSum, nums[I]);
        }
        
        return maxSum;
        
        
    }
};