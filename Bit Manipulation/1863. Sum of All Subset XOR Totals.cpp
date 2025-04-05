// 2025/04/05
class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int ans = 0;
            for(int mask = 0; mask < (1 << nums.size()); ++mask){
                int tmp = 0;
                for(int i = 0; i < nums.size(); ++i){
                    if(mask & (1 << i)) tmp ^= nums[i];
                }
                ans += tmp;
            }
            return ans;
        }
    };
    /*
    mask 會有
    0000, 0001 ... 1111
    mask 總共會和 nums.size() 相同大小，例如 4
    而排列組合 0001 是 代表 xor nums[0]
    所以會遇到 0101 就是 xor nums[2] 和 nums[0]
    最後就會把每個排列組合都 xor 到
    */