// LeetCode 413. Arithmetic Slices.cpp

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        if(A.size() < 3)
            return 0;
        
        int prev = A[1] - A[0], cnt = 2, I, ans = 0, n;
        for(I = 2; I < A.size(); I++)
        {
            if(A[I] - A[I - 1] == prev)
                cnt++;
            else
            {
                prev = A[I] - A[I - 1];
                
                if(cnt == 3)
                    ans += (cnt - 2);
                else if(cnt > 3)
                {
                    n = cnt - 2;
                    n = (n * (n + 1)) / 2;
                    ans += n;
                }
                
                cnt = 2;
                
            }
        }
        
        
        if(cnt == 3)
            ans += (cnt - 2);
        else if(cnt > 3)
        {
            n = cnt - 2;
            n = (n * (n + 1)) / 2;
            ans += n;
        }
        
        
        return ans;
        
    }
};