class Solution {
public:
    int mySqrt(int x) {
        
        long long int number = x, sqrt = 0;
        
        while(sqrt <= number){
            if(sqrt * sqrt == number){
                return sqrt;
            } else if(sqrt * sqrt > number){
                return sqrt - 1;
            }
            
            sqrt++;
        }
        
        return 1;
    }
};