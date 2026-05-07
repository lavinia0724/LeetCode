// 2026/05/07
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;

            for (int x : nums) {
                if ((x >> bit) & 1) count++;
            }

            if (count % 3 != 0) {
                ans |= (1 << bit);
            }
        }
        return ans;
    }
};