// 2026/01/21
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            // x 是 2 的話一定不可能可以組，因為 x OR (x + 1) 一定是奇數；2 是唯一的偶數質數
            if (x == 2) {
                ans.push_back(-1);
                continue;
            }

            int trailingOnes = 0;
            // count trailing ones in x
            while ((x & (1LL << trailingOnes)) != 0) trailingOnes++;

            // remove all trailing ones
            long long base = x >> trailingOnes;
            base <<= trailingOnes;

            // add back trailingOnes - 1 ones to get minimum ans
            long long res = base | ((1 << (trailingOnes - 1)) - 1);
            ans.push_back((int)res);
        }

        return ans;
    }
};

/*
ex: nums = 7 (111)

trailing ones = 3, 去掉最左邊的 1
base = 000
res = 000 or 011 = 3
3 OR 4 = 7

nums = 5 (101)
trailing ones = 1
base = 100, 去掉所有從 LSB 來的 1 後剩下碰到第一個 0 後的值 
res = 100 → 4
4 OR 5 = 5
*/