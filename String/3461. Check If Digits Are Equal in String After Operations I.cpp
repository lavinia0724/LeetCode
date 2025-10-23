// 2025/10/23
class Solution {
public:
    bool hasSameDigits(string s) {
        if(s.size() < 2) return false;

        vector<int> nums;
        for(auto item: s) nums.emplace_back(int(item));

        while(nums.size() > 2){
            vector<int> tmp;
            for(int i = 0; i < nums.size()-1; ++i){
                tmp.emplace_back((nums[i] + nums[i+1]) % 10);
            }
            nums = tmp;
        }
        return nums[0] == nums[1];
    }
};