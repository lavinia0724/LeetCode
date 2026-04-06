// 2026/04/06
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        // 1. 將機器人與射程配對並按位置排序
        vector<pair<int, int>> robotData(n);
        for (int i = 0; i < n; ++i) robotData[i] = {robots[i], distance[i]};
        sort(robotData.begin(), robotData.end());
        sort(walls.begin(), walls.end());

        // 預先計算每個機器人獨立的貢獻
        // leftHits[i]: 第 i 個機器人往左射能擊中的牆數 (會被第 i-1 個機器人擋住)
        // rightHits[i]: 第 i 個機器人往右射能擊中的牆數 (會被第 i+1 個機器人擋住)
        // gapWalls[i]: 第 i-1 與第 i 個機器人之間所有的牆壁總數
        vector<int> leftHits(n), rightHits(n), gapWalls(n, 0);

        for (int i = 0; i < n; ++i) {
            int pos = robotData[i].first;
            int dist = robotData[i].second;

            // 計算往左射：範圍 [max(pos-dist, 左邊機器人位置+1), pos]
            int leftLimit = (i == 0) ? pos - dist : max(pos - dist, robotData[i - 1].first + 1);
            auto itL1 = lower_bound(walls.begin(), walls.end(), leftLimit);
            auto itL2 = upper_bound(walls.begin(), walls.end(), pos);
            leftHits[i] = itL2 - itL1;

            // 計算往右射：範圍 [pos, min(pos+dist, 右邊機器人位置-1)]
            int rightLimit = (i == n - 1) ? pos + dist : min(pos + dist, robotData[i + 1].first - 1);
            auto itR1 = lower_bound(walls.begin(), walls.end(), pos);
            auto itR2 = upper_bound(walls.begin(), walls.end(), rightLimit);
            rightHits[i] = itR2 - itR1;

            // 計算與前一個機器人間的牆壁總數 (用於處理重疊)
            if (i > 0) {
                auto itG1 = lower_bound(walls.begin(), walls.end(), robotData[i - 1].first);
                auto itG2 = upper_bound(walls.begin(), walls.end(), pos);
                gapWalls[i] = itG2 - itG1;
            }
        }

        // 2. 動態規劃 (DP)
        // dpLeft: 考慮到第 i 個機器人且它「向左射」時的最大牆壁數
        // dpRight: 考慮到第 i 個機器人且它「向右射」時的最大牆壁數
        long long dpLeft = leftHits[0];
        long long dpRight = 0; // 第一個向右射的貢獻會在處理下一個機器人時計算

        for (int i = 1; i < n; ++i) {
            // 如果當前機器人 i 選擇「向左射」
            // 情況 A: 前一個機器人也向左，完全不重疊
            long long case1 = dpLeft + leftHits[i];
            // 情況 B: 前一個機器人向右，兩者可能在間隙中重疊
            // 公式：(前一個總數 - 前一個向右射的貢獻) + 兩者在間隙中的實際破壞數
            long long combinedGap = min((long long)rightHits[i - 1] + leftHits[i], (long long)gapWalls[i]);
            long long case2 = (dpRight - 0) + combinedGap; 
            
            long long nextDpLeft = max(case1, case2);

            // 如果當前機器人 i 選擇「向右射」
            // 由於向右射不影響前面的機器人，直接從前一個狀態的最優解轉移
            // 注意：前一個向右射的貢獻在上一輪已經算過了
            long long nextDpRight = max(dpLeft, dpRight + rightHits[i - 1]);

            dpLeft = nextDpLeft;
            dpRight = nextDpRight;
        }

        // 如果最後一個機器人選擇向右射，要加上它最後一段的貢獻
        return (int)max(dpLeft, dpRight + rightHits[n - 1]);
    }
};