// InterviewBit - Counting Triangles.cpp

int Solution::nTriang(vector<int> &A) {
    
    sort(A.begin(), A.end());
    
    int I, J, K, SZ = A.size(), cnt = 0, MOD = 1000000000 + 7;
    for(I = 0; I < SZ - 2; I++)
    {
        K = I + 2;
        for(J = I + 1; J < SZ - 1 && A[I] != 0; J++)
        {
            while(K < SZ && (A[I] + A[J] > A[K]))
                K++;
              
            cnt =((cnt % MOD) + ((K % MOD - (1 + J) % MOD)) % MOD) % MOD;
            
        }

    }
    
    return cnt % MOD;    
    
}
