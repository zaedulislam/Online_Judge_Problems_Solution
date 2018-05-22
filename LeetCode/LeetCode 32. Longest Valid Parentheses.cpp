// LeetCode 32. Longest Valid Parentheses.cpp

#define pci pair<char, int>
#define pii pair<int, int>

const int SIZE = 1e5 + 10;
int trace[SIZE];
stack<pci> S;
vector<pii> correctRange;




class Solution {
public:
    int longestValidParentheses(string s) {
        
        string str = s;
        
        while(!S.empty())
            S.pop();
        
        for(int I = 0; I < SIZE; I++)
            trace[I] = 0;
        
        correctRange.clear();
        
        
        int I, len = str.length(), startIdx, endIdx;
        for(I = 0; I < len; I++)
        {
            if(str[I] == '(')
                S.push(pci(str[I], I));
            else if(str[I] == ')' && !S.empty())
            {
                pci TOP = S.top();
                S.pop();
                char ch = TOP.first;
                
                if(ch == '(' && str[I] == ')')
                {
                    startIdx = TOP.second;
                    endIdx = I;
                    
                    trace[startIdx] = 1;
                    trace[endIdx] = 1;
                    
                }
            
                
            }
            
        }
        
        
        startIdx = -1, endIdx = -1;
        for(I = 0; I < len; I++)
        {
            if(trace[I] == 0 && startIdx != -1 && endIdx != -1)
            {
                correctRange.push_back(pii(startIdx, endIdx));
                startIdx = -1;
                endIdx = -1;
            }
            if(trace[I] == 1 && startIdx == -1)
                startIdx = I;
            if(trace[I] == 1 && startIdx != -1)
                endIdx = I;
            
        }
        
        
        if(startIdx != -1 && endIdx != -1)
            correctRange.push_back(pii(startIdx, endIdx));
        
        
        int maxLen = 0, SZ = correctRange.size();
        for(I = 0; I < SZ; I++)
        {
            startIdx = correctRange[I].first;
            endIdx = correctRange[I].second;
    
            if(endIdx - startIdx + 1 > maxLen)
                maxLen = endIdx - startIdx + 1;
                
        }
        
        
        return maxLen;
        
    }
    
};
