// 2026/05/02
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i-1]) ans += prices[i] - prices[i-1]; // 只要今天比昨天貴，就賺差價
        }
        return ans;
    }
};