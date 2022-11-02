class Solution {
public:
    static int getReversedNumber(int n){
        int reversedNumber = 0;
        
        while(n){
            int digit = n % 10;
            n /= 10;
            reversedNumber += digit;
            
            if(n != 0){
                reversedNumber *= 10;
            }
        }
        
        return reversedNumber;
    }
    
  
    int countDistinctIntegers(vector<int>& nums) {
        int arrayLength = nums.size();
        set<int> distinctNumber;
        
        for(int i = 0;i < arrayLength; i++){
            if(distinctNumber.find(nums[i]) == distinctNumber.end()){
                distinctNumber.insert(nums[i]);
            }
            
            int reversedNumber = getReversedNumber(nums[i]);
            
            if(distinctNumber.find(reversedNumber) == distinctNumber.end()){
                distinctNumber.insert(reversedNumber);
            }
            
        }
        
        return distinctNumber.size();
    }
};
