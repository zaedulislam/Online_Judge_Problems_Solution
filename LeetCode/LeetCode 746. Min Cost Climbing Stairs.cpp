// LeetCode 746. Min Cost Climbing Stairs.cpp

const int SIZE = 1000 + 5;
#define INTMAX (1 << 31) - 1
int ar[SIZE], memo[SIZE], n;




int F(int pos)
{
    if(pos >= n)
        return 0;
    
    if(memo[pos] != -1)
        return memo[pos];
    
    int ret1 = INTMAX, ret2 = INTMAX;
    ret1 = ar[pos] + F(pos + 1);
    ret2 = ar[pos] + F(pos + 2);
    
    return memo[pos] = min(ret1, ret2);
}



class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        
        for(int I = 0; I < n; I++)
        {
            ar[I] = cost[I];
            memo[I] = -1;
        }
            
        return min(F(0), F(1));
		
    }
};