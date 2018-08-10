// LeetCode 139. Word Break.cpp
#define SET(ar) memset(ar, -1, sizeof(ar))
const int SIZE = 1e3 + 10;

class Solution {
public:
    
    map<string, int> MAP;
    int memo[SIZE];
    
    bool DictionaryContain(string str)
    {
        if(MAP.find(str) != MAP.end())
            return true;
        
        return false;
    }
    
    
    bool WordBreak(string s)
    {
        int I, len = s.length();
        
        if(len == 0)
            return true;
        
        if(memo[len] == -1)
        {
            memo[len] = 0;
            
            for(I = 1; I <= len; I++)
            {
                string prefix = s.substr(0, I);
                
                if(DictionaryContain(prefix) && WordBreak(s.substr(I, len - I)))
                {
                    memo[len] = 1;
                    return memo[len];
                }
            }
        }
        
        return memo[len];
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        
        
        for(int I = 0; I < wordDict.size(); I++)
            MAP[wordDict[I]] = 1;
        
        SET(memo);
        
        if(WordBreak(s) == 1)
            return true;
        else
            return false;
        
    }
};