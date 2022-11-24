class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashMap;

        for(int i = 0; i < s.size(); i++){
            hashMap[s[i]]++;
        }

        int index = -1;
        for(int i = 0; i < s.size(); i++){
            if(hashMap[s[i]] == 1){
                index = i;
                break;
            }
        }

        return index;
    }
};
