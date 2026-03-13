// 2026/03/13
class Solution {
public:
    bool can(long long T, int H, vector<int> &w) {
        long long total = 0;

        for (long long t : w) {
            long long val = (2 * T) / t;
            long long x = (long long)((sqrt(1 + 4 * 2.0 * T / t) - 1) / 2);

            total += x;
            if (total >= H) return true;
        }
        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0;
        long long right = 1e16;
        long long ans = right;

        while (left <= right) {
            long long mid = (left + right) / 2;
            if (can(mid, mountainHeight, workerTimes)) {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
/*
找出最大 x 使：
t * x(x+1)/2 ≤ T
也就是找 x(x+1) ≤ 2T/t
*/