class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsLength = nums.size();
        vector<int> left(numsLength, 1), right(numsLength, 1), result;
        
        for(int i = 0; i < numsLength; i++){
            if(i == 0){
                left[i] = nums[i];
            } else{
                left[i] = left[i - 1] * nums[i];   
            }
        }
        
        for(int i = numsLength - 1; i >= 0; i--){
            if(i == numsLength - 1){
                right[i] = nums[i];
            } else{
                right[i] = right[i + 1] * nums[i];    
            }
        }
        
        
        for(int i = 0; i < numsLength; i++){
            if(i == 0){
                result.push_back(right[i + 1]);
            } else if(i == numsLength - 1){
                result.push_back(left[i - 1]);
            } else {
                result.push_back(left[i - 1] * right[i + 1]);
            }
        }
        
        return result;
        
    }
};
