// 2024/07/06
class Solution {
public:
    int passThePillow(int n, int time) {
        int quotient = time / (n-1);
        int mod = time % (n-1);
        if(quotient % 2 == 0) {
            return mod + 1;
        }
        else{
            return n - mod;
        }
    }
};