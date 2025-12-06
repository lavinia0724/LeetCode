// 2025/12/06
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> dp(n + 1, 0), prefixSum(n + 1, 0);
        dp[0] = 1; // dp 紀錄 0~i 時的分割方式數量
        prefixSum[0] = 1; // prefixSum 是 dp[0] + dp[1] + ... + dp[i]，dp 的前綴和

        deque<int> maxdq, mindq; // 紀錄的是 idx

        int left = 0;
        for(int i = 0; i < n; ++i){
            // 為了讓 maxdq 維持由大到小的序列，如果 nums[i] 比 back 還大或相等，back 不可能再成為區間最大值，所以移除
            while(!maxdq.empty() && nums[maxdq.back()] <= nums[i]) maxdq.pop_back();
            maxdq.push_back(i);

            // 同理
            while(!mindq.empty() && nums[mindq.back()] >= nums[i]) mindq.pop_back();
            mindq.push_back(i);

            while(!maxdq.empty() && !mindq.empty() && nums[maxdq.front()] - nums[mindq.front()] > k){
                // 如果 max - min > k -> 此區間不合法，需要右移左邊界 left
                if(maxdq.front() == left) maxdq.pop_front();
                if(mindq.front() == left) mindq.pop_front();
                left++;
            }

            // dp[i+1] = sum of dp[left..i]
            long long res = prefixSum[i];
            // 如果 left 有往右移，那現在 res 會變少，因為 prefixSum 是 dp 的前綴和，也就是少了幾格 dp 的可能性
            // 要先加 MOD 不然可能會是負的
            if(left > 0) res = (res - prefixSum[left-1] + MOD) % MOD; 

            dp[i+1] = res; // 更新我這格 dp 的值是我現在 res 是我 idx left ~i 有多少種分割方式 
            prefixSum[i+1] = (prefixSum[i] + dp[i+1]) % MOD; // 繼續加前綴和
        }
        return dp[n];
    }
};