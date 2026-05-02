// 2026/05/02
class Solution {
public:
    bool isgood(int x){
        bool check = false;
        while(x > 0){
            int rem = x % 10;
            if(rem == 3 || rem == 4 || rem == 7) return false;
            if(rem == 2 || rem == 5 || rem == 6 || rem == 9) check = true;
            x /= 10;
        }
        return check;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            if(isgood(i)) ans++;
        }
        return ans;
    }
};