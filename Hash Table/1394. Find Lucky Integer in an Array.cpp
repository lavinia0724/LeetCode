// 2025/07/05
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        int ans = -1;
        for(auto num: arr) mp[num]++;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(it->second == it->first) ans = max(ans, it->first);
        }
        return ans;
    }
};