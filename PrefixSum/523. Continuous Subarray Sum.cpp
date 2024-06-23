// 2024/06/08
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;

        unordered_map<int, int> modSeen;
        int prefixSum[nums.size()+5];

        modSeen[0] = 0;
        prefixSum[0] = 0;

        for(int i = 1; i <= nums.size(); ++i){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];

            // 存 prefixSum % k 餘數，如果有別格與他相減 == 0 且這兩格之間不只差 1，就可以確定這區間和是 k 的倍數
            // prefix[j] = Q1 * k + R1, prefix[i] = Q2 * k + R2
            // ((Q1 - Q2) * k + (R1 - R2)) % k == 0
            // prefix[j] % k == prefix[i] % k 
            prefixSum[i] %= k;

            if(modSeen.find(prefixSum[i]) != modSeen.end()){
                if(i - modSeen[prefixSum[i]] > 1) return true;
            }
            else modSeen[prefixSum[i]] = i;
        }
        
        return false;
    }
};