class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> hashMap;

        for(auto n: deck){
            hashMap[n]++;
        }

        bool isPartitionPossible = false;
        for(int x = 2; x <= deck.size(); x++){
            int count = 0;
            for(auto n: hashMap){
                if(n.second % x != 0){
                    break;
                } 

                count++;
            }

            if(hashMap.size() == count){
                isPartitionPossible = true;
                break;
            }
        }

        return isPartitionPossible;
    }
};
