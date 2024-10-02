// 2024/10/02
class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.first < b.first;
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for(int i = 0; i < arr.size(); ++i) mp[arr[i]] = 0;

        int idx = 1;
        for(auto it = mp.begin(); it != mp.end(); ++it, ++idx){
            it->second = idx;
        }
        
        vector<int> ans;
        for(int i = 0; i < arr.size(); ++i) ans.emplace_back(mp[arr[i]]);
        return ans;
    }
};