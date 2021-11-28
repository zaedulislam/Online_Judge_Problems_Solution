class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int pos = 0;
        
        for(int num: nums){
            if(pos < 2 || num != nums[pos - 2]){
                nums[pos++] = num;
            }
        }  
        
        return pos;
    }
};