class Solution {
public:
    int commonFactors(int a, int b) {
        int commonFactorCount = 1;
        int gcd = __gcd(a, b);
        for(int n = 2; n <= gcd; n++){
            if(a % n == 0 && b % n == 0){
                commonFactorCount++;
            }
        }

        return commonFactorCount;
    }
};
