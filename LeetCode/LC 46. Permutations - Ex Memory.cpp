class Solution {
public:
    void generatePermutation(int pos, vector<int>& nums, vector<int>& currentPermutation, vector<vector<int>>& permutations, vector<bool>& taken){
        
        if(pos == nums.size()){
            permutations.push_back(currentPermutation);
            return;
        }


        for(int i = 0; i < nums.size(); i++){
            if(taken[i] == false){
                taken[i] = true;
                currentPermutation[pos] = nums[i];
                generatePermutation(pos + 1, nums, currentPermutation, permutations, taken);
                taken[i] = false;
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<bool> taken(nums.size(), false);
        vector<int> currentPermutation(nums.size(), 0);

        generatePermutation(0, nums, currentPermutation, permutations, taken);

        return permutations;
    }
};
