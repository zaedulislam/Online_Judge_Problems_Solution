// InterviewBit - Diffk [O(n)].cpp

int Solution::diffPossible(vector<int> &A, int B) {
    
    int I = 0, J = 1, SZ = A.size(), k = B;
    
    while(I < SZ - 1)
    {
        while(J < SZ && A[J] - A[I] < k)
            J++;
        
        if(A[J] - A[I] == k)
            return true;
        
        I++;
        if(I == J)
            J++;
    }
    
    
    return false;
}