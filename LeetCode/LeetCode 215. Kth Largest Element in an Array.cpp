// LeetCode 215. Kth Largest Element in an Array.cpp

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        return nums[nums.size() - k];
        
    }
};