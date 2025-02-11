// 2025/02/11
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            while(s.find(part) != string::npos){
                auto partFirstIdx = s.find(part);
                // s = 從 0 到 part 頭的位址的字串 + 從 part 頭往後整個 part size 之後的位址開始到整個 s 字串結束
                s = s.substr(0, partFirstIdx) + s.substr(partFirstIdx + part.size()); 
            }
            return s;
        }
    };