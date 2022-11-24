class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;

        for(auto n: nums){
            if(hashSet.find(n) != hashSet.end()){
                return true;
            }

            hashSet.insert(n);
        }

        return false;
    }
};
