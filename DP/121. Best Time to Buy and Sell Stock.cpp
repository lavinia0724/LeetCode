// 2026/05/02
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = INT_MIN;
        for(int price: prices){
            buy = max(buy, -price);
            sell = max(sell, price + buy);
        }
        return sell;
    }
};