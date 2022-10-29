class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPointer = 0, rightPointer = numbers.size() - 1;
        
        while(leftPointer < rightPointer){
            int sum = numbers[leftPointer] + numbers[rightPointer];
            
            if(sum == target){
                return {leftPointer + 1, rightPointer + 1};
            }
            if(sum > target){
                rightPointer--;
            } else{
                leftPointer++;
            }
        }
        
        return {};
    }
};
