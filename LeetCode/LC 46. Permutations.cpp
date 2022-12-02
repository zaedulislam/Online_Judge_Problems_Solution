class Solution {
public:
    void generatePermutation(int pos, vector<vector<int>>& permutations, vector<int>& nums){
        if(pos == nums.size()){
            permutations.push_back(nums);
            return;
        }


        for(int i = pos; i < nums.size(); i++){
            swap(nums[pos], nums[i]);
            generatePermutation(pos + 1, permutations, nums);
            swap(nums[pos], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;

        generatePermutation(0, permutations, nums);

        return permutations;
    }
};
