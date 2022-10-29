// LeetCode 136. Single Number.cpp

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int I, XOR = 0;
        for(I = 0; I < nums.size(); I++)
            XOR ^= nums[I];
        
        return XOR;
    }
};
