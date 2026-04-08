// 2026/04/08
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        for(auto q: queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            for(int i = l; i <= r; i += k){
                nums[i] = (1LL * nums[i] * q[3]) % MOD;
            }
        }

        int ans = 0;
        for(auto num: nums){
            ans ^= num;
        }
        return ans;
    }
};