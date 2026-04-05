// 2026/04/05
class Solution {
public:
    bool judgeCircle(string moves) {
        int UDcnt = 0, LRcnt = 0;
        for(auto item: moves){
            if(item == 'D') UDcnt--;
            else if(item == 'U') UDcnt++;
            else if(item == 'R') LRcnt++;
            else if(item == 'L') LRcnt--;
        }
        return (UDcnt == 0 && LRcnt == 0);
    }
};