// 2025/12/05
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for(int i = 1; i <= n; ++i) prefixSum[i] += prefixSum[i-1] + nums[i-1];

        int ans = 0;
        for(int left = 1; left < n; ++left){
            if((prefixSum[n] - prefixSum[left] * 2) % 2 == 0) ans++;
        }
        return ans;
    }
};