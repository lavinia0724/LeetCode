// 2026/05/03
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size() != s.size()) return false;
        string s1 = s + s;
        return s1.find(goal) != string::npos;
    }
};