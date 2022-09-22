class Solution {
public:
    vector<bool> taken;
    vector<int> permutation;
    vector<vector<int>> result;
    
    void backtrack(vector<int> nums, int index){
        if(index == nums.size()){
            result.push_back(permutation);
                
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(taken[i] == false){
                taken[i] = true;
                permutation[index] = nums[i];
                backtrack(nums, index + 1);
                taken[i] = false;
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i: nums){
            taken.push_back(false);
            permutation.push_back(0);
        }
        
        
        backtrack(nums, 0);
        
        return result;
    }
};
