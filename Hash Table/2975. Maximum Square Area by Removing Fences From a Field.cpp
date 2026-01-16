// 2026/01/16
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        // 加上邊界
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> horizonDiff; // 記錄所有水平距離
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++)  horizonDiff.insert(hFences[j] - hFences[i]);
        }

        long long maxSide = 0;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long diff = vFences[j] - vFences[i];
                if (horizonDiff.count(diff)) maxSide = max(maxSide, diff); // 如果水平也有這段距離，存最大的
            }
        }

        if (maxSide == 0) return -1;
        return (maxSide * maxSide) % MOD;
    }
};