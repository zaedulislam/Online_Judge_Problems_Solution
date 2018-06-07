// LeetCode 647. Palindromic Substrings [O(n^3)].cpp

class Solution {
public:
    int countSubstrings(string s) {
        
        int I, J, i, j, len = s.length(), cnt = 0;
        
        for(I = 0; I < len; I++)
        {
            for(J = I; J < len; J++)
            {
                i = I;
                j = J;
                bool ok = true;
                while(i <= j)
                {
                    if(s[i] != s[j])
                        ok = false;
                    i++;
                    j--;
                }
                
                if(ok)
                    cnt++;
                
            }
        }
        
        return cnt;
        
    }
};