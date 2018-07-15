// LeetCode 791. Custom Sort String.cpp

class Solution {
public:
   
    string customSortString(string S, string T)
    {
        int mapS[26 + 5], mapT[26 + 5];
        
        memset(mapS, 0, sizeof(mapS));
        memset(mapT, 0, sizeof(mapT));
        
        int I, lenS = S.length(), lenT = T.length();
        for(I = 0; I < lenS; I++)
            mapS[S[I] - 'a']++;

        for(I = 0; I < lenT; I++)
            mapT[T[I] - 'a']++;

        string ans = "";
        for(I = 0; I < lenS; I++)
        {
            if(mapS[S[I] - 'a'] == 1 && mapT[S[I] - 'a'] > 0)
            {
                while(mapT[S[I] - 'a'] > 0)
                {
                    ans += S[I];
                    mapT[S[I] - 'a']--;
                }
            }
        }


        for(I = 0; I < 26; I++)
        {
            if(mapS[I] == 0 && mapT[I] > 0)
            {
                while(mapT[I] > 0)
                {
                    ans += (char)(I + 'a');
                    mapT[I]--;
                }
            }
        }

        return ans;

    }
};