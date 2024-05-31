// 2024/05/31
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> mapNums;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            mapNums[nums[i]] += 1;
        }
        for(auto iter = mapNums.begin(); iter != mapNums.end(); ++iter){
            if(iter->second == 1){
                ans.push_back(iter->first);
            }
        }
        return ans;
    }
};