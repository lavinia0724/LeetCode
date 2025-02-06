// 2025/02/06
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> possibleProducts;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                possibleProducts[nums[i] * nums[j]]++;
            }
        }   

        int totalPossibleTuple = 0;
        for(auto [product, val]: possibleProducts){
            if(val < 2) continue;

            // 排列組合: C val 取 2 
            int possibleSet = val * (val - 1) / 2;
            // 每個 possibleSet 必有八種可能，也就是 (a, b, c, d) 必有八種可能排列組合
            totalPossibleTuple += 8 * possibleSet;
        }
        return totalPossibleTuple;
    }
};