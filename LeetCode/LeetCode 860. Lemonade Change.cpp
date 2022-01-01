class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int numberOfFiveDollar = 0;
        int numberOfTenDollar = 0;
        
        for(int bill: bills){
            if(bill == 5){
                numberOfFiveDollar++;
            } else if(bill == 10){
                if(numberOfFiveDollar == 0){
                    return false;
                }                
                
                numberOfFiveDollar--;
                numberOfTenDollar++;
            } else{
                if(numberOfTenDollar > 0 && numberOfFiveDollar > 0){
                    numberOfFiveDollar--;
                    numberOfTenDollar--;
                } else if(numberOfFiveDollar >= 3){
                    numberOfFiveDollar -= 3;
                } else {
                    return false;
                }
            }  
        }
        
        return true;
    }
};