/*
  Time Complexity: O(N)
  Space Complexity: O(N)
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> uniqueNumber;
        
        long long totalSum = 0;
        for(int num: nums){
            totalSum += num;
            uniqueNumber.insert(num);
        }
        
        long long uniqueSum = 0;
        for(int num: uniqueNumber){
            uniqueSum += num;
        }
        
        return (3 * uniqueSum - totalSum) / 2;
    }
};
