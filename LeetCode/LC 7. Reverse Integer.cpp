class Solution {
public:
    int reverse(int x) {
        int isNegative = x < 0 ? true : false; 
        
        int reversedNumber = 0;
        
        while(x){
            int digit = x % 10;
            x /= 10;
            reversedNumber += abs(digit);
            
            if(x != 0){
                if(isNegative && (-1) * reversedNumber < INT_MIN / 10){
                    return 0;
                }
                else if(reversedNumber > INT_MAX / 10){
                    return 0;
                }
                
                reversedNumber *= 10;
            }
        }
        
        reversedNumber = isNegative ? (-1) * reversedNumber : reversedNumber;
        
        return reversedNumber;
    }
};
