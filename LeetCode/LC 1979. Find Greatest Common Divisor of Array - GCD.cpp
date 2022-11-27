class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX, largest = INT_MIN;
        for(auto n: nums){
            smallest = min(n, smallest);
            largest = max(n, largest);
        }

        return __gcd(smallest, largest);
    }
};
