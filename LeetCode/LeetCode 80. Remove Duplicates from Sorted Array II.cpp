class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        int pos = 0;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[pos] == nums[i]){
                if(pos - 1 < 0){
                    nums[++pos] = nums[i];
                }
                if(pos - 1 >= 0 && nums[pos] != nums[pos - 1]){
                    nums[++pos] = nums[i];    
                } 
                
            } else{
                nums[++pos] = nums[i];
            }
        }     
        
        return pos + 1;
    }
};