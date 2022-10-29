class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int arrayLength = nums.size();
        
        unordered_map<int, int> hashMap;
        
        for(int i = 0; i < arrayLength; i++){
            int complement = target - nums[i];
            
            if(hashMap.find(nums[i]) != hashMap.end()){
                return {hashMap[nums[i]], i};
            } else{
                hashMap[complement] = i;
            }
        }
        
        return {};
    }
};
