class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX, largest = INT_MIN;
        for(auto n: nums){
            smallest = min(n, smallest);
            largest = max(n, largest);
        }

        int gcd = 1;
        for(int n = min(smallest, largest); n >= 1; n--){
            if(smallest % n == 0 && largest % n == 0){
                gcd = n;
                break;
            }
        }

        return gcd;
    }
};
