// 2025/02/09
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            // j - i == nums[j] - nums[i] is good pair
            // 所以用 hash table 判斷 j - nums[j] == i - nums[i]
            long long int goodPairCnt = 0;
            unordered_map<int, int> pairMp;
            for(int i = 0; i < nums.size(); ++i){
                if(pairMp.find(nums[i] - i) != pairMp.end()) goodPairCnt += pairMp[nums[i] - i];
                pairMp[nums[i] - i]++;
            }
            // 但題目要的是 bad pair，因此要用總共 pair 數量 C nums.size() 取 2 再減掉 good pair 數量
            return ((nums.size() - 1) * nums.size() / 2) - goodPairCnt;
        }
    };