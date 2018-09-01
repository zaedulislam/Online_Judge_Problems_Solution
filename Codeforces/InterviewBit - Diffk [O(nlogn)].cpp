// InterviewBit - Diffk [O(nlogn)].cpp

int Solution::diffPossible(vector<int> &A, int B) {
    
    int I, SZ = A.size(), k = B;
    
    for(I = 0; I < SZ; I++)
    {
        int first = I + 1, last = SZ - 1, mid, key;
        while(first <= last)
        {
            mid = (first + last) / 2;
            key = A[I] + k;
            
            if(A[mid] == key)
                return true;
            else if(A[mid] > key)
                last = mid - 1;
            else
                first = mid + 1;
            
        }
        
    }
    
    return false;
}
