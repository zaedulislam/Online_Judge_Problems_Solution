class Solution {
public:
    bool recurse(int n){
        if(n == 1){
            return true;
        }

        if(n % 2 != 0){
            return false;
        }

        return recurse(n / 2);
    }


    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }    

        return recurse(n);
    }
};


// Simplified Version
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }    

        if(n == 1){
            return true;
        }

        return n % 2 == 0 ? isPowerOfTwo(n / 2) : false;
    }
};
