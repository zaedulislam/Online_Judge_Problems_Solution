/*
    Time Complexity: O(logN)
    Space complexity: O(1)
*/


class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
        
        int low = 1, high = (x >> 1), ans;
        
        while(low <= high){
            long int mid = (low + high) >> 1;
            cout << "mid: " << mid << endl;
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