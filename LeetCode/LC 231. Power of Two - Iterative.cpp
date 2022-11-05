class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }

        int x;
        for(int i = 0; i <= 30; i++){   
            if(i == 0){
                x = 1;
            } else{
                x <<= 1;
            }

            if(x == n){
                return true;
            }
        }

        return false;
    }
};
