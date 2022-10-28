class Solution {
public:
    static string convertIntegerToString(int n){
        if(n == 0){
            return "0";
        }
        
        string str = "";
        
        while(n){
            int digit = n % 10;
            n /= 10;
            str.insert(str.begin(), 48 + digit);
        }
        
        return str;
    }
    
    
    static bool comparator(string x, string y){
        string xy = x + y;
        string yx = y + x;
        
        return xy > yx;
    }
    
    
    string largestNumber(vector<int>& nums) {
        vector<string> numbers;
        
        for(int num: nums){
            numbers.push_back(convertIntegerToString(num));
        }
        
        sort(numbers.begin(), numbers.end(), comparator); 
        
        if(numbers[0] == "0"){
            return "0";
        }
        
        string result = "";
            
        for(string num: numbers){
            result += num;
        }
        
        return result;
    }
};
