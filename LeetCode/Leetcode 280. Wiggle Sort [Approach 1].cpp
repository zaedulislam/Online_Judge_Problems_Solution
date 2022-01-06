/*
    Time Complexity: O(Nlog(N))
    Space Complexity: O(N)
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ar[50000 + 1];
        
        for(int i = 0; i < nums.size(); i++){
            ar[i] = nums[i];
        }
        
        int index = nums.size() - 1;
        if(nums.size() & 1){
            index -= 1;
        }
        
        int pos = nums.size() - 1;
        while(index >= 0){
            nums[index] = ar[pos];
            index -= 2;
            pos -= 1;
        }
        
        index = nums.size() - 2;
        if(nums.size() & 1){
            index += 1;
        }
        
        while(index >= 0){
            nums[index] = ar[pos];
            index -= 2;
            pos -= 1;
        }
    }
};