// 2026/04/24
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, underline = 0;
        for(auto move: moves){
            if(move == 'R') right++;
            else if(move == 'L') left++;
            else if(move == '_') underline++;
        }
        return max((right + underline - left), (left + underline - right));
    }
};