/*
    Time Complexity: O(nlogn)
    Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        int pos = 0;
    
        for(int i = 0; i < nums.size(); i++){
        
            if(nums[pos] < nums[i]){
                nums[++pos] = nums[i];
            }    
        }
        
        
        return pos + 1;
    }
};