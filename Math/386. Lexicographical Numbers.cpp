// 2024/09/21
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        int tmp = 1;
        for(int i = 0; i < n; ++i){
            ans.emplace_back(tmp);

            if(tmp * 10 <= n) tmp *= 10;
            else{
                // 除非個位數已經是 9 了，或者 tmp +1 > n 了
                while(tmp % 10 == 9 || tmp >= n) tmp /= 10;
                tmp += 1;
            }
        }

        return ans;
    }
};