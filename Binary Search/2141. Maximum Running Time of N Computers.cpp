// 2025/12/01
class Solution {
public:
    bool canRun(long long T, int n, const vector<int>& batteries){
        // 是否能讓 n 台電腦同時運行 T 分鐘
        long long total = 0;
        for(long long b: batteries){
            total += min(b, T);
            if(total >= (long long)n * T) return true;
        }
        return total >= (long long)n * T;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);

        long long left = 0, right = sum / n;

        while(left < right){
            long long mid = (left + right + 1) / 2;
            if(canRun(mid, n, batteries)) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};