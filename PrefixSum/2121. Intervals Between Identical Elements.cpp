// 2026/04/24
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<long long>> mp;
        vector<long long> ans(n, 0);

        for(int i = 0; i < n; ++i) mp[arr[i]].push_back(i);

        for(auto& it: mp){
            vector<long long>& tmp = it.second;
            long long total = accumulate(tmp.begin(), tmp.end(), 0LL);
            long long leftidxSum = 0;
            for(int j = 0; j < tmp.size(); ++j){
                long long leftSum = tmp[j] * j - leftidxSum;
                long long rightSum = llabs(tmp[j] * (tmp.size() - j - 1) - (total - leftidxSum - tmp[j]));
                
                ans[tmp[j]] = leftSum + rightSum;
                leftidxSum += tmp[j];
            }
        }
        return ans;
    }
};