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