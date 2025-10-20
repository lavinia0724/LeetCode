// 2025/10/20
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto operation: operations){
            if(operation[0] == '+' || operation[2] == '+') ans++;
            else ans--;
        }
        return ans;
    }
};