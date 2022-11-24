class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        int arrayLength = nums.size();

        for(int i = 0; i < arrayLength; i++){
            if(hashMap.find(nums[i]) != hashMap.end()){
                int j = hashMap[nums[i]];

                if(abs(j - i) <= k){
                    return true;
                }
            }

            hashMap[nums[i]] = i; 
        }

        return false;
    }
};
