// 2026/03/06
class Solution {
public:
    bool checkOnesSegment(string s) {
        int check = 0;
        for(auto c: s){
            if(c == '1' && check == 0) check = 1;
            else if(c == '1' && check == 1) continue;
            else if(c == '0' && check == 1) check = 2;

            if(c == '1' && check > 1) return false;
        }
        return true;
    }
};