class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPointer = 0, rightPointer = numbers.size() - 1;
        
        while(leftPointer < rightPointer){
            if(numbers[leftPointer] + numbers[rightPointer] == target){
                return {leftPointer + 1, rightPointer + 1};
            }
            if(numbers[leftPointer] + numbers[rightPointer] > target){
                rightPointer--;
            } else{
                leftPointer++;
            }
        }
        
        return {};
    }
};
