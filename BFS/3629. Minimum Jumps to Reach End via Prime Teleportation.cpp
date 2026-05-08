// 2026/05/08
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        // 找出 nums 中的最大值，等等篩選只需要做到 maxVal
        int maxVal = *max_element(nums.begin(), nums.end());

        // 一開始先假設每個數的最小質因數都是自己
        vector<int> spf(maxVal + 1); // smallest prime factor
        for (int i = 0; i <= maxVal; ++i) spf[i] = i;

        // 0 和 1 不是質數，避免後面判斷出錯
        if (maxVal >= 0) spf[0] = 0;
        if (maxVal >= 1) spf[1] = 1;

        // 建 smallest prime factor
        for (int i = 2; i * i <= maxVal; ++i) {
            if (spf[i] == i) { // 如果 i 是質數，更新質數表
                for (int j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        // factorToIndices[p] 存所有 nums[index] 可以被質數 p 整除的 index
        unordered_map<int, vector<int>> factorToIndices;

        // 對每個 nums[i] 做質因數分解
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            while (x > 1) {
                // p 是目前 x 的最小質因數
                int p = spf[x];

                // 代表 nums[i] 可以被 p 整除
                factorToIndices[p].push_back(i);

                // 把所有 p 的因數都除掉，避免重複加入同一個質因數
                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        // BFS 求最短路徑
        vector<int> dist(n, -1); //  dist[i] = 從 index 0 走到 index i 需要的最少 jump 數
        queue<int> q;

        // 起點是 index 0，距離是 0
        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // 如果已經走到最後一格，因為 BFS 特性，這一定是最短距離
            if (i == n - 1) {
                return dist[i];
            }

            // 先處理 Adjacent Step
            if (i - 1 >= 0 && dist[i - 1] == -1) { // 可以從 i 走到 i - 1
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }
            if (i + 1 < n && dist[i + 1] == -1) {  // 可以從 i 走到 i + 1
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            // 接著處理 Prime Teleportation
            int val = nums[i];
            if (val >= 2 && spf[val] == val) {
                int p = val;
                if (factorToIndices.count(p)) {
                    for (int j : factorToIndices[p]) {
                        // j != i 是因為題目要求 teleport 到 j != i
                        // dist[j] == -1 代表這個位置還沒有被走過
                        if (j != i && dist[j] == -1) {
                            dist[j] = dist[i] + 1;
                            q.push(j);
                        }
                    }
                    factorToIndices.erase(p);
                }
            }
        }
        return -1;
    }
};