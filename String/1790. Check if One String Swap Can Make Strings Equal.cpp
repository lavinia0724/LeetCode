// 2025/02/05
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int needChangePos = -1;
        string needChangeChar = "";
        for(int i = 0; i < s2.size(); ++i){
            if(s1[i] != s2[i] && needChangePos == -1){
                needChangePos = i;
                needChangeChar = s1[i];
                needChangeChar += s2[i];
            }
            else if(s1[i] != s2[i] && needChangePos != -1){
                if(s2[i] != needChangeChar[0] || s1[i] != needChangeChar[1] || needChangeChar == "") return false;
                needChangeChar = ""; // 這邊 needChangePos 不做處理，用來控制只能換一次位置; needChangeChar 用來判斷後面是否有第二次需要換位置的字元
            }
        }
        if(needChangeChar != "") return false;
        return true;
    }
};