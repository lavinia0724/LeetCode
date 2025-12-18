// 2025/12/18
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> A(n), B(n);

        long long base = 0;
        for (int i = 0; i < n; i++) {
            A[i] = strategy[i] * prices[i];       // 原本的狀況
            B[i] = (1 - strategy[i]) * prices[i]; // 改成 sell 的額外收益 (1-(-1)賣比買多兩倍收益、1-0賣比不變多一倍收益、1-1反正本來就要賣)
            base += A[i]; // 紀錄原始貢獻和
        }

        // 計算 prefixSum
        vector<long long> prefixSumA(n + 1, 0), prefixSumB(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSumA[i + 1] = prefixSumA[i] + A[i];
            prefixSumB[i + 1] = prefixSumB[i] + B[i];
        }

        // 做題目要的 sliding window
        long long bestDelta = 0;
        int half = k / 2;
        for (int L = 0; L + k <= n; L++) { // 看區間最左邊要從哪裡開始
            long long loss = prefixSumA[L + half] - prefixSumA[L]; // 前 k/2 被設成 hold 後虧的錢
            long long gain = prefixSumB[L + k] - prefixSumB[L + half]; // 後 k/2 被設成 sell 後賺的錢
            bestDelta = max(bestDelta, gain - loss); // 看啥時候賺的比虧的多最多
        }
        return base + bestDelta;
    }
};