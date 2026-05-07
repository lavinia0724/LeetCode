// 2026/05/07
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> dp;

        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        for (int i = 0; i < n; ++i) {
            int h = envelopes[i][1];

            auto it = lower_bound(dp.begin(), dp.end(), h);
            if (it == dp.end()) { // 因為 w 已經被 sort 由小到大排序好了，所以這裡只要抓 h 就好
                dp.push_back(h);
            }
            else *it = h;
        }

        return dp.size();
    }
};