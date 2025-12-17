// 2025/12/17
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long baseSum = 0;
        vector<long long> pos, neg; // pos: 翻轉後有變大、neg: 翻轉後變小了

        for (int x : nums) {
            baseSum += x;
            long long gain = (x ^ k) - x; // 翻轉後的值 - 原本值
            if (gain > 0) pos.push_back(gain);
            else neg.push_back(gain);
        }

        long long gainSum = 0;
        for (long long gain : pos) gainSum += gain;

        // 如果正 gain 數量是偶數，直接全選
        if (pos.size() % 2 == 0) {
            return baseSum + gainSum;
        }

        // 否則必須修正成偶數
        long long loss1 = LLONG_MAX; // 拿掉一個正 gain
        for (long long gain : pos) loss1 = min(loss1, gain);

        long long loss2 = LLONG_MAX; // 加上一個負 gain
        for (long long gain : neg) loss2 = min(loss2, -gain);

        long long fixLoss = min(loss1, loss2); // 看要拿掉一個正的還是加上一個負的比較好

        return baseSum + gainSum - fixLoss;
    }
};
/*
一次操作會讓 兩個節點 XOR k

每個節點被 XOR k 的次數，只在乎「奇偶」
XOR 偶數次 = 沒變
XOR 奇數次 = 變成 nums[i] ^ k
*/