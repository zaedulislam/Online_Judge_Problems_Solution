// LeetCode 347. Top K Frequent Elements.cpp

#define pii pair<int, int>
unordered_map<int, int> MAP1;
map<pii, int > MAP2;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        MAP1.clear();
        MAP2.clear();
        
        for(int I = 0; I < nums.size(); I++)
            MAP1[nums[I]]++;
        
        for(auto it = MAP1.begin(); it != MAP1.end(); it++)
            MAP2[pii(it->second, it->first)] = 1;
        
        
        vector<int> ans;
        int cnt = 0;
        
        map<pii, int> :: iterator it = MAP2.end();
        it--;
        while(it != MAP2.begin())
        {
            if(cnt == k)
                break;
            
            ans.push_back((it->first).second);
            cnt++;
            
            it--;
        }
        
        if(cnt < k)
            ans.push_back((it->first).second);
            
        
        return ans;
        
    }
};