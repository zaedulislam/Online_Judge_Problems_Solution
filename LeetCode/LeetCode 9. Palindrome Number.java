class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        
        int reversedNumber = 0;
        while(x > reversedNumber){
            int digit = x % 10;
            x /= 10;
            reversedNumber = (reversedNumber * 10) + digit;
        }

        return x == reversedNumber || x == reversedNumber / 10;
    }
}
