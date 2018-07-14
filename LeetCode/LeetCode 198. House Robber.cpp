// LeetCode 198. House Robber.cpp

const int SIZE = 1e5 + 5;
long long ar[SIZE], memo[SIZE], n;




long long F(int pos)
{
    if(pos >= n)
        return 0;
    
    if(memo[pos] != -1)
        return memo[pos];
    
    long long ret1 = 0, ret2 = 0;
    ret1 = ar[pos] + F(pos + 2);
    ret2 = F(pos + 1);
    
    return memo[pos] = max(ret1, ret2);
}



class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        n = nums.size();
        for(int I = 0; I < n; I++)
        {
            ar[I] = nums[I];
            memo[I] = -1;
        }
            
        
        return F(0);
    }
};