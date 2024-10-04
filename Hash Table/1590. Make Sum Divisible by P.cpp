// 2024/10/03
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sumNums = accumulate(nums.begin(), nums.end(), 0LL); // 0LL 是 0 的 long long 表示法
        
        int target = sumNums % p;
        int ans = nums.size(), prefixSum = 0;
        map<int, int> modMp;    

        modMp[0] = -1;
        for(int i = 0; i < nums.size(); ++i){
            prefixSum = (prefixSum + nums[i]) % p;
            int need = (prefixSum - target + p) % p;
            
            modMp[prefixSum] = i;
            if(modMp.find(need) != modMp.end())ans = min(ans, i - modMp[need]);
        }
        return ans == nums.size() ? -1 : ans;
    }
};