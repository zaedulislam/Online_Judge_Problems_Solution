/*
    Time Complexity: O(N)
    Space Complexity: O(N)
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int arraySize = 50000 + 1, frequencyCounter[arraySize], numsLen = nums.size(), maxValue = 0;
        
        for(int num: nums){
            maxValue = max(maxValue, num);
            frequencyCounter[num] += 1;
        }
        
        int index = numsLen - 1;
        if(numsLen & 1){
            index -= 1;
        }
        
        int firstIterator, secondIterator;
        for(firstIterator = maxValue; firstIterator >= 0; firstIterator--){
            while(frequencyCounter[firstIterator] > 0 && index >= 0){
                nums[index] = firstIterator;
                index -= 2;
                frequencyCounter[firstIterator]--;
            }
            
            if(index < 0){
                break;
            }
        }
        
        index = numsLen - 2;
        if(numsLen & 1){
            index += 1;
        }
        
        for(secondIterator = firstIterator; secondIterator >= 0; secondIterator--){
            while(frequencyCounter[secondIterator] > 0 && index >= 0){
                nums[index] = secondIterator;
                index -= 2;
                frequencyCounter[secondIterator]--;
            }
            
            if(index < 0){
                break;
            }
        }
        
    }
};