// 2026/05/07
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            ans ^= x; // XOR 的特性，相同數字做 XOR 兩次後會 = 0
        }
        return ans;
    }
};