/*
- Time Complexity: O(n)
    Each element is visited at most twice (once in the first loop to find the duplicate and once in the second loop to restore the numbers).
- Space Complexity: O(1)
    All manipulation is done in place, so no additional storage (barring one variable) is needed.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicateNumber = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int cur = abs(nums[i]);
            
            if(nums[cur] < 0){
                duplicateNumber = cur;
                break;
            } else{
                nums[cur] *= -1;
            }
            
        }
        
        // Restore numbers
        for (auto& num : nums)
            num = abs(num);
        
        return duplicateNumber;   
    }
};
