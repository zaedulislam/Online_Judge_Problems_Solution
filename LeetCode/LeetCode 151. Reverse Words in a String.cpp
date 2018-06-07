// LeetCode 151. Reverse Words in a String.cpp

class Solution {
public:
     void reverseWords(string &s) {
         
        vector<string> words;
     
        string S = "";
        int I = 0, len = s.length();
        while(I < len)
        {
            if(s[I] == ' ')
            {
                if(S.length() == 0)
                {
                    I++;
                    continue;
                }
                else
                {
                    S += ' ';
                    while(s[I] == ' ')
                        I++;
                }
            }
            else
            {
                S += s[I];
                I++;
            }
            
        }
        
         
        len = S.length();
        if(S[len - 1] == ' ')
            S.erase(S.end() - 1);
    
        
        string w = "";
        len = S.length();
        for(I = 0; I < len; I++)
        {
            if(S[I] == ' ')
            {
                words.push_back(w);
                w = "";
            }
            else
                w += S[I];
        } 
        
        
        if(w.length() != 0)
            words.push_back(w);

        s = "";
        for(int I = words.size() - 1; I >= 0; I--)
        {
            s += words[I];
            if(I != 0)
                s += ' ';
        }
        
    }
};