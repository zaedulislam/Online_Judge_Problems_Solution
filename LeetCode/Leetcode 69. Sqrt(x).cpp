/*
    Time Complexity: O(logN)
    Space complexity: O(1)
*/


class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x, ans;
        
        while(low <= high){
            long int mid = (low + high) >> 1;
            
            long int square = mid * mid;
            
            if(square == x){
                return mid;
            } else if (square > x){
                high = mid - 1;
            } else{
                low = mid + 1;
                ans = mid;
            }
            
        }
        
        return ans;
    }
};
