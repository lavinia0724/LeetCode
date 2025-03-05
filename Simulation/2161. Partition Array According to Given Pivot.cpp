// 2025/03/05
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> less;
            vector<int> greater;
            vector<int> equal;
            for(auto num: nums){
                if(num < pivot) less.push_back(num);
                else if(num > pivot) greater.push_back(num);
                else equal.push_back(num);
            }
            vector<int> ans;
            ans.insert(ans.end(), less.begin(), less.end());
            ans.insert(ans.end(), equal.begin(), equal.end());
            ans.insert(ans.end(), greater.begin(), greater.end());
            return ans;
        }
    };