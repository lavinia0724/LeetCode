// 2026/05/02
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k >= n/2){ // k >= n/2，就可以直接看比前一天賺錢就賣
            int ans = 0;
            for(int i = 1; i < n; ++i){
                if(prices[i] > prices[i-1]) ans += prices[i] - prices[i-1];
            }
            return ans;
        }

        vector<int> buy(k+1, INT_MIN);
        vector<int> sell(k+1, 0);

        buy[0] = 0;
        sell[0] = 0;
        for(auto price: prices){
            for(int j = 1; j <= k; ++j){ // 做第 j 次買賣
                // 做第 j 次買: 
                // buy[j] 不買
                // sell[j-1] - price 今天買 (先完成 j-1 次交易（sell[j-1]), 然後用這些錢買股票（-price）)
                buy[j] = max(buy[j], sell[j-1] - price);

                // 做第 j 次賣: 
                // sell[j] 不賣
                // buy[j-1] + price 今天買 我之前已經做完第 j 次買（buy[j]）, 現在把股票賣掉（+price）)
                sell[j] = max(sell[j], buy[j] + price);
            }
        }
        return sell[k];
    }
};