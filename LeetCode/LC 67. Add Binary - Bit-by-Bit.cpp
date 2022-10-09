class Solution {
public:
    string addBinary(string a, string b) {
        int maxLength = max(a.length(), b.length());
        int aLength = a.length() - 1;
        int bLength = b.length() - 1;
        int carry = 0;
        string result = "";
        
        while(aLength >= 0 || bLength >= 0){
            int aChar = aLength > -1 ? a[aLength] - 48 : 0;
            int bChar = bLength > -1 ? b[bLength] - 48 : 0;
            int sum = ((aChar + bChar) % 2 + carry) % 2;
            
            if(aChar == 1 && bChar == 1){
                carry = 1;
            } else if((aChar == 1 || bChar == 1) && carry == 1){
                carry = 1;
            } else {
                carry = 0;
            }
            
            result.insert(result.begin(), sum + 48);
            
            aLength--;
            bLength--;
        }
        
        if(carry == 1){
            result.insert(result.begin(), '1');
        }
        
        
        return result;
    }
};
