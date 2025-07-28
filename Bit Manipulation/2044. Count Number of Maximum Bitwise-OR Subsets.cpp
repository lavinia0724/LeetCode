// 2025/07/28
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0, ans = 0;
        for(auto num: nums) maxi |= num;
        
        // 其實就是枚舉，總共有 nums.size() * 2 種可能，用 0 ~ maxiMask 來枚舉
        int maxiMask = 1 << nums.size();
        for(int maskBit = 0; maskBit < maxiMask; ++maskBit){
            int tmp = 0;
            // 這裡 maskBit 是 int，所以用 i 來表示他的每一位數(binary 是否為 1)，如果是 1 那就要 OR 對應 idx 的 num
            for(int i = 0; i < nums.size(); ++i){ // 最多 nums.size 個 bit
                if((maskBit >> i) & 1){ // 依序看每個 bit，就是依序位移 i bit，就會把每個 bit 都移到最右邊看一次 & 1
                    tmp |= nums[i];
                }
            }
            if(tmp == maxi) ans++;
        }
        return ans;
    }
};