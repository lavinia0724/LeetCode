// 2024/06/09
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> modSeen;
        int prefixSum = 0;
        int ans = 0;

        modSeen[0] = 1;

        for(int i = 0; i < nums.size(); ++i){
            // 因為可能有負數，所以 (nums[i-1] + k) % k
            prefixSum = (prefixSum + (nums[i] % k) + k) % k;

            ans += modSeen[prefixSum];
            modSeen[prefixSum]++;
        }
        
        return ans;
    }
};
/*
[4, 5, 0, -2, -3, 1]
prefixSum:
[4, 9, 9, 7, 4, 5]
prefixSum mod:
[4, 4, 4, 2, 4, 0]

for i = 0, nums[i] = 4, prefixSum mod = 4, [4], modSeen[4] = 1
for i = 1, nums[i] = 5, prefixSum mod = 4, [4, 4], ans += modSeen[4], modSeen[4]++ = 2
代表有第一個 4 後的 [5] 5 可以被 5 整除

for i = 2, nums[i] = 0, prefixSum mod = 4, [4, 4, 4], ans += modSeen[4], modSeen[4]++ = 3
代表有第一個 4 後的 [5, 0] 5 + 0 可以被 5 整除，以及第二個 4 後的 [0] 可以被 5 整除 
(ans + (modSeen[4] = 2 代表前面有兩個餘 4 的 prefixMod 可以組合，所以加 2))

for i = 3, nums[i] = -2, prefixSum mod = 2, [4, 4, 4, 2], modSeen[2] = 1
for i = 4, nums[i] = -3, prefixSum mod = 4, [4, 4, 4, 2, 4], modSeen[4]++ = 4
代表有第一個 4 後的 [5, 0, -2, -3] 5 + 0 + -2 + -3 可以被 5 整除，以及第二個 4 後的 [0, -2, -3] 5 + 0 + -2 + -3 可以被 5 整除，還有第三個 4 後的 [-2, -3] -2 + -3 可以被 5 整除

for i = 5, nums[i] = 1, prefixSum mod = 0, [4, 4, 4, 2, 4, 0], modSeen[0]++ = 2
代表有第一個 0 後的 [4, 5, 0, -2, -3, 1] 可以被 5 整除
*/