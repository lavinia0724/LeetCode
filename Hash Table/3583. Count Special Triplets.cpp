// 2025/12/09
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        unordered_map<long long, long long> leftCnt, rightCnt;
        for(auto num: nums) rightCnt[num]++;

        long long ans = 0;
        for(int j = 0; j < nums.size(); ++j){
            long long target = 2 * nums[j];
            rightCnt[nums[j]]--;

            long long leftMatch = leftCnt[target];
            long long rightMatch = rightCnt[target];

            ans = (ans +leftMatch * rightMatch) % MOD;

            leftCnt[nums[j]]++; 
        }
        return ans;
    }
};