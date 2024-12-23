// 2024/12/23
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); ++i) pq.push(nums[i]);

        long long int ans = 0;
        for(int i = 0; i < k; ++i){
            auto top = pq.top();
            pq.pop();
            ans += top;
            pq.push(ceil(double(top)/3));
        }

        return ans;
    }
};