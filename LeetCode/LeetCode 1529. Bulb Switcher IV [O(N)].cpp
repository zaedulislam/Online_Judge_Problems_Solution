// LeetCode 1529. Bulb Switcher IV [O(N)].cpp

class Solution {
public:
    int minFlips(string target) {
        
        int startIndex = 0, minimumFlipsRequired  = 0;
       	while(target[startIndex] == '0'){
		    startIndex++;
	    }
        
        if(startIndex == target.length()){
            return minimumFlipsRequired;
        }

        
        for(int i = startIndex; i < target.length(); i++){
            if(i + 1 < target.length() && target[i] != target[i + 1]){
                minimumFlipsRequired++;
            }
        }
        
        return minimumFlipsRequired + 1;
    }
};