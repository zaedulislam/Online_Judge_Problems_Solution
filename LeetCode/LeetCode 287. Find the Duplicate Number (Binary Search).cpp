/*
    Time Complexity: O(nlogn)
    Space Complexity: O(1)
*/


class Solution {
public:
    
    int smallOrEqual(int current, vector<int>& nums){
        int cnt = 0;
        
        for(int num: nums){
            if(num <= current){
                cnt++;
            }
        }
        
        return cnt;
    }
    
    int findDuplicate(vector<int>& nums) {
        
        int first = 1, last = nums.size(), duplicateNumber = 0;
        while(first <= last){
            int mid = (first + last) >> 1;


            if(smallOrEqual(mid, nums) > mid){
                duplicateNumber = mid;
                last = mid - 1;
            } else {
                first = mid + 1;
            }

        }
        
        return duplicateNumber;
    }
};