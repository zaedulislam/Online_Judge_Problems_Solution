// LeetCode 122. Best Time to Buy and Sell Stock II.cpp

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0)
            return 0;
        
        int maxProfit = 0, buy = prices[0], sell = -1, I = 1, SZ = prices.size();
        while(I < SZ)
        {
            while(I < SZ && prices[I - 1] <= prices[I])
            {
                sell = prices[I];
                I++;
            }
            

            if(buy != -1 && sell != -1)
            {
                maxProfit += (sell - buy);
                sell = -1;
            }
            
            buy = prices[I];
            I++;
            
        }
        
        return maxProfit;
        
        
    }
};