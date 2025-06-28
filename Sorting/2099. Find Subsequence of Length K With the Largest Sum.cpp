// 2025/06/28
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());

        for(int i = 0; i < k; ++i) tmp.pop_back();

        for(auto num: tmp){
            auto it = std::find(nums.begin(), nums.end(), num);
            if(it != nums.end()) nums.erase(it);
        }

        return nums;
    }
};