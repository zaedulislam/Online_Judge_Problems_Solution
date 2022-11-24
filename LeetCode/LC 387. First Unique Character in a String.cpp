class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> flag(26, -1);

        for(int i = 0; i < s.size(); i++){
            int x = s[i] - 97;

            if(flag[x] == -1){
                flag[x] = i;
            } else if(flag[x] >= 0){
                flag[x] = -2;
            }
        }

        int index = -1;
        for(auto ch: s){
            int x = ch - 97;

            if(flag[x] >= 0){
                index = flag[x];
                break;
            }
        }

        return index;
    }
};
