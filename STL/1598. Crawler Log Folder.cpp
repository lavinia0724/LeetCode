// 2024/07/10
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for(int i = 0; i < logs.size(); ++i){
            if(logs[i][0] != '.'){
                s.push(logs[i]);
            }
            if(logs[i] == "../" && !s.empty()) s.pop();
        }
        return s.size();
    }
};