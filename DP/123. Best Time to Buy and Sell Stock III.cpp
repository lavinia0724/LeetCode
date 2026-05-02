// 2026/05/02
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int buy1 = INT_MIN, sell1 = INT_MIN, buy2 = INT_MIN, sell2 = INT_MIN;
        for(auto price: prices){ // O(n) 更新 DP
            buy1 = max(buy1, -price);
            sell1 = max(sell1, price + buy1);
            buy2 = max(buy2, sell1 - price); // 可行因為題目沒規定不能當天買當天售出
            sell2 = max(sell2, price + buy2);
        }
        return sell2;
    }
};