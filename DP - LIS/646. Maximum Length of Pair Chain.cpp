// 2026/05/07
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> listdp;
        for(auto x: pairs){
            int head = x[0];
            int tail = x[1];

            auto it = lower_bound(listdp.begin(), listdp.end(), head);
            if (it == listdp.end()) listdp.push_back(tail);
            else *it = min(*it, tail); // 同長度 chain 保留較小結尾，之後才更容易接新的 pair
        }
        return listdp.size();
    }
};