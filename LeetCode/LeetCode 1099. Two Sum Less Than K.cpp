class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int maximumSum = -1;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int currentSum = nums[i] + nums[j];
                
                if(currentSum < k){
                    maximumSum = max(maximumSum, currentSum);   
                }
            }
        }
        
        
        return maximumSum;
    }
};