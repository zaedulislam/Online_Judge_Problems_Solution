class Solution {
public:
    void generateUniquePermutations(int pos, vector<vector<int>>& uniquePermutations, vector<int>& nums){
        if(pos == nums.size()){
            uniquePermutations.push_back(nums);
            return;
        }

        for(int i = pos; i < nums.size(); i++){
            if(nums[pos] != nums[i]){
                swap(nums[pos], nums[i]);
                generateUniquePermutations(pos + 1, uniquePermutations, nums);
                swap(nums[pos], nums[i]);
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> uniquePermutations;

        generateUniquePermutations(0, uniquePermutations, nums);

        return uniquePermutations;
    }
};
