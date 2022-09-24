/*
  Time Complexity: O(N)
  Space Complexity: O(N)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        vector<int> sortedArray(100000 + 1, 0);
        int kLargestElement = 0;        
        
        for(int num: nums){
            if(num >= 0){
                sortedArray[num]++;
            }
        }
        
        for(int i = 100000; i >= 0; i--){
            while(sortedArray[i] > 0 && k > 0){
                sortedArray[i]--;
                k--;
            }
            
            if(k == 0){
                kLargestElement = i;
                return kLargestElement;
            }
        }
        
        fill(sortedArray.begin(), sortedArray.end(), 0);
        
        for(int num: nums){
            if(num < 0){
                sortedArray[(-1) * num]++;
            }    
        }
        
        for(int i = 1; i <= 100000; i++){
            while(sortedArray[i] > 0 && k > 0){
                sortedArray[i]--;
                k--;
            }
            
            if(k == 0){
                kLargestElement = (-1) * i;
                break;
            }
        }
        
        return kLargestElement;
    }
};
