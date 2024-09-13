// 2024/09/13
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix(arr.size() + 1, 0);
        for(int i = 1; i <= arr.size(); ++i){
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }

        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); ++i){
            ans[i] = prefix[queries[i][1] + 1] ^ prefix[queries[i][0]];
            // ex: [1, 3] = [0, 3] ^ [0, 0]
        }
        return ans;
    }
};