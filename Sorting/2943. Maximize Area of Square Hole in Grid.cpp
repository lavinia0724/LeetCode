// 2026/01/15
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxH = 1, maxV = 1, now = 1; // 找最大連續的 horizon 邊長
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) now++;
            else now = 1;
            maxH = max(maxH, now);
        }

        now = 1; // 找最大連續的 vertical 邊長
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) now++;
            else  now = 1;
            maxV = max(maxV, now);
        }

        // 因為 ex: 邊長 2 ~ 4 長度是 4 - 2 + 1，所以這裡要 + 1
        int side = min(maxH + 1, maxV + 1);
        return side * side;
    }
};