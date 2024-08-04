// 2024/08/05
class Solution {
    struct prefixSum{
        int sum;
        int idx;

        bool operator < (const prefixSum &other) const{
            return sum > other.sum;
        }
    };
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<prefixSum> pq;

        for(int i = 0; i < n; ++i) pq.push({nums[i], i});
        
        int cnt = 1, ans = 0, mod = 1e9 + 7;
        while(cnt <= right){
            prefixSum now = pq.top();
            pq.pop();

            if(cnt++ >= left) {
                ans = (ans + now.sum) % mod;
            }

            if(now.idx < n - 1) {
                pq.push({now.sum + nums[now.idx + 1], now.idx + 1});
            }
        }
        return ans;
    }
};