class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        
        int arrayLength = nums.size();
        for(int i = 0; i < arrayLength; i++){
            if(nums[i] == 0){
                zero++;
            } else if(nums[i] == 1){
                one++;
            } else{
                two++;
            }
        }
        
        for(int i = 0; i < arrayLength; i++){
            if(zero){
                nums[i] = 0;
                zero--;
            } else if(one){
                nums[i] = 1;
                one--;
            } else{
                nums[i] = 2;
                two--;
            }
        }
    }
};
