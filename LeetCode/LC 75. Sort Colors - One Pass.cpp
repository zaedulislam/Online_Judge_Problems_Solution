class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, current = 0, high = nums.size() - 1;
        
        while(current <= high){
            if(nums[current] == 0){
                swap(nums[low], nums[current]);
                current++;
                low++;
            } else if(nums[current] == 1){
                current++;
            } else{
                swap(nums[current], nums[high]);
                high--;
            }
        }
        
    }
};
