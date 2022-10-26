class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int arrayLength = nums.size();
        
        if(arrayLength <= 2){
            return true;
        }
        
        int removeIndex = -1, count = 0;
        
        for(int i = 1; i < arrayLength; i++){
            if(nums[i] <= nums[i - 1]){
                count++;
                removeIndex = i;
            }
        }
        
        
        if(count >= 2){
            return false;
        }   else if(removeIndex == -1 ||  removeIndex == arrayLength - 1 || removeIndex == 1){
                return true;
        } else if(nums[removeIndex - 1] < nums[removeIndex + 1]){
                return true;
        }   else if(removeIndex - 2 >= 0 && nums[removeIndex - 2] < nums[removeIndex]){
                return true;
        }
        
        
        return false;
    }
};
