// LeetCode 151. Reverse Words in a String [O(1) space].cpp

class Solution {
public:
    void reverseWords(string &s) {
        int I, J, K, len = s.length();
        
        while(s.length() - 1 >= 0 && s[s.length() - 1] == ' ')
            s.erase(s.end() - 1);
        
        I = 0;
        while(I < s.length() && s[I] == ' ')
            s.erase(s.begin());
        
        
        I = 0;
        while(I < s.length())
        {
            while(s[I] == ' ' && I + 1 < s.length() && s[I + 1] == ' ')
                s.erase(s.begin() + I);
            
            I++;        
        }
        
        reverse(s.begin(), s.end());
  
        I = 0, J = 0;
        while(J < s.length())
        {
            while(J < s.length() && s[J] != ' ')
                J++;
            
            K = J - 1;
            
            while(I <= K)
            {
                swap(s[I], s[K]);
                I++;
                K--;
            }
            
            J++;
            I = J;
            
        }
        
    }
    
};