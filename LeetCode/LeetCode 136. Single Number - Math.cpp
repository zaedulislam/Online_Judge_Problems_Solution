class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sumOfSet = 0, sumOfNums = 0;
        unordered_set<int> hashSet;
        
        for(int num: nums){
            if(hashSet.find(num) == hashSet.end()){
                hashSet.insert(num);
                sumOfSet += num;
            }
            
            sumOfNums += num;
        }
        
        return 2 * sumOfSet - sumOfNums;
    }
};
