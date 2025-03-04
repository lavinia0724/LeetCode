// 2025/03/04
class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while(n > 0){
                if(n % 3 == 0) n/= 3;
                else {
                    n -= 1;
                    if(n % 3 != 0) return false;
                    n /= 3;
                }
            }
            return true;
        }
    };