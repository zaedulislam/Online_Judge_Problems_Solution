// LeetCode 611. Valid Triangle Number [O(n^2*logn)].cpp

class Solution {
public:
    
    
    
    int BinarySearch(vector<int> ar, int I, int J, int K, int n)
    {
        int first = J + 1, last = n - 1, mid;
        while(first <= last)
        {
            mid = (first + last) / 2;
            if(ar[I] + ar[J] > ar[mid])
                first = mid + 1;
            else
                last = mid - 1;
        }
        
        return first;
    }
    
    
    
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int I, J, K, SZ = nums.size(), cnt = 0;
        
        for(I = 0; I < SZ - 2; I++)
        {
            K = I + 2;
            for(J = I + 1; J < SZ - 1; J++)
            {
                K = BinarySearch(nums, I, J, K, SZ);
                cnt += K - 1 - J;
            }
        }
        
        return cnt;
    }
};