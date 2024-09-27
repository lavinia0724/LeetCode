// 2024/09/22
class Solution {
public:
    int countStep(int n, long long int prefix1, long long int prefix2){
        int step = 0;
        while(prefix1 <= n){
            step += min((long long int)(n + 1), prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return step;
    }

    int findKthNumber(int n, int k) {
        int ans = 1;
        k--;
        
        while(k > 0){
            int step = countStep(n, ans, ans + 1);
            if(step <= k){
                ans += 1;
                k -= step;
            }
            else{
                ans *= 10;
                k--;
            }
        }

        return ans;
    }
};

/* 參考 editorial
prefix1 prefix2 是樹與樹

ex: k = 159
prefix1 = 1: 10 11 ... 19
prefix2 = 2: 20 21 ... 29

step = 0 + min(159 ,2) - 1 = 2 - 1 = 1

prefix1 *= 10 = 100
prefix2 *= 10 = 200

prefix1 = 100: 100 101 ... 109
prefix2 = 200: 200 201 ... 209

step = 1 + min(159, 200) - 100 = 159 - 100 = 1 + 59 = 60

return 60
*/