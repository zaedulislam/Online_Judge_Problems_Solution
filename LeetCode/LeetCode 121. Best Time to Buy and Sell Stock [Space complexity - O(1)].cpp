// LeetCode 121. Best Time to Buy and Sell Stock [Space complexity - O(1)].cpp

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int I, SZ = prices.size(), minPrice = (1 << 31) - 1, maxPrice = 0;
        for(I = 0; I < SZ; I++)
        {
            if(prices[I] < minPrice)
                minPrice = prices[I];
            else if(prices[I] - minPrice > maxPrice)
                maxPrice = prices[I] - minPrice;
            
        }
        
        return maxPrice;
    }
};