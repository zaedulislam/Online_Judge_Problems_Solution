// LeetCode 121. Best Time to Buy and Sell Stock.cpp

#define CLR(ar) memset(ar, 0, sizeof(ar))
const int SIZE = 2e6 + 10;
int mn[SIZE], mx[SIZE];



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0)
            return 0;
        
        CLR(mx);
        CLR(mn);
        
        int I, SZ = prices.size();
        
        mn[0] = prices[0];
        for(I = 1; I < SZ; I++)
            mn[I] = min(mn[I - 1], prices[I]);
        
        mx[SZ - 1] = prices[SZ - 1];
        for(I = SZ - 2; I >= 0; I--)
            mx[I] = max(mx[I + 1], prices[I]);  
        
        int ans = 0;
        for(I = 0; I < SZ - 1; I++)
            ans = max(ans, mx[I + 1] - mn[I]);
        
        return ans;
        
    }
};
