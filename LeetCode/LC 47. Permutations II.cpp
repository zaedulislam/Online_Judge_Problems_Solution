class Solution {
public:
    bool shouldSwap(int start, int indexOfPossibleOption, vector<int>& nums){
        for(int i = start; i < indexOfPossibleOption; i++){
            if(nums[i] == nums[indexOfPossibleOption]){
                return false;
            }
        }

        return true;
    }

    
    void generateUniquePermutations(int start, vector<vector<int>>& uniquePermutations, vector<int>& nums){
        if(start == nums.size()){
            uniquePermutations.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++){
            if(shouldSwap(start, i, nums)){
                swap(nums[start], nums[i]);
                generateUniquePermutations(start + 1, uniquePermutations, nums);
                swap(nums[start], nums[i]);
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> uniquePermutations;

        generateUniquePermutations(0, uniquePermutations, nums);

        return uniquePermutations;
    }
};
