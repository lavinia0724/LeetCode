// 2026/05/07
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lisdp;

        for(int x: nums){
            auto it = lower_bound(lisdp.begin(), lisdp.end(), x);

            if (it == lisdp.end()) lisdp.push_back(x);
            else *it = x;
        }

        return lisdp.size();
    }
};