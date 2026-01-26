// 2026/01/26
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int mini = INT_MAX;
        vector<vector<int>> ans;
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i] - arr[i-1] < mini){
                mini = arr[i] - arr[i-1];
                ans.clear();
                ans.push_back({arr[i-1], arr[i]});
            }
            else if(arr[i] - arr[i-1] == mini) ans.push_back({arr[i-1], arr[i]});
        }
        return ans;
    }
};