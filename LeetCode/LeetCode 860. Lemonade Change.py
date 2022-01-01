class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        numberOfFiveDollar: int = 0
        numberOfTenDollar: int = 0
        
        for bill in bills:
            if bill == 5:
                numberOfFiveDollar += 1
            elif bill == 10:
                if numberOfFiveDollar == 0:
                    return False
                
                numberOfFiveDollar -= 1
                numberOfTenDollar += 1
            else:
                if numberOfTenDollar > 0 and numberOfFiveDollar > 0:
                    numberOfFiveDollar -= 1
                    numberOfTenDollar -= 1
                elif numberOfFiveDollar >= 3:
                    numberOfFiveDollar -= 3
                else:
                    return False
                
        
        return True