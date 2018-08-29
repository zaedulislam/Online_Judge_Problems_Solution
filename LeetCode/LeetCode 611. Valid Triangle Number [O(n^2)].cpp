// LeetCode 611. Valid Triangle Number [O(n^2)].cpp

class Solution {
public:
    
    
    
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int I, J, K, SZ = nums.size(), cnt = 0;
        
        for(I = 0; I < SZ - 2; I++)
        {
            K = I + 2;
            for(J = I + 1; J < SZ - 1 && nums[I] != 0; J++)
            {
                while(K < SZ && (nums[I] + nums[J] > nums[K]))
                    K++;
                
                cnt += K - 1 - J;
            }
        }
        
        return cnt;
    }
};