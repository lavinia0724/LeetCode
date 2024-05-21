// 2024/05/21 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});

        for(int i = 0; i < nums.size(); ++i){
            vector<vector<int>> tmp = ans;
            for(int j = 0; j < ans.size(); ++j){
                tmp[j].push_back(nums[i]);
            }

            for(int j = 0; j < tmp.size(); ++j){
                ans.push_back(tmp[j]);
            }
        }

        return ans;
    }
};