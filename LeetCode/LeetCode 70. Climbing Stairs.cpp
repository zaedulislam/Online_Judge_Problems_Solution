// LeetCode 70. Climbing Stairs.cpp

const int SIZE = 1000 + 5;
#define INTMAX (1 << 31) - 1
int memo[SIZE], top;



int F(int pos)
{
    if(pos == top)
        return 1;
    if(pos > top)
        return 0;
    
    if(memo[pos] != -1)
        return memo[pos];
    
    int ret1 = 0, ret2 = 0;
    if(pos + 1 <= top)
        ret1 = F(pos + 1);
    if(pos + 2 <= top)
        ret2 = F(pos + 2);
    
    return memo[pos] = ret1 + ret2;
}




class Solution {
public:
    int climbStairs(int n) {
        top = n;
        for(int I = 0; I <= n; I++)
            memo[I] = -1;

        
        return F(0);
    }
};