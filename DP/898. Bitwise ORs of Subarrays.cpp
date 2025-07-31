// 2025/07/31
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> current, ans;
        for(auto num: arr){
            unordered_set<int> temp;
            temp.insert(num);

            for(auto cur_num: current){
                temp.insert(cur_num | num);
            }
            ans.insert(temp.begin(), temp.end());
            current = temp;
        }
        return ans.size();
    }
};