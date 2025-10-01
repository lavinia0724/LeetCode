// 2024/07/07
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles / numExchange > 0){
            ans += numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }
        return ans;
    }
};

//2025/10/01
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, remind = 0;
        while(numBottles > 0){
            ans += numBottles;
            numBottles += remind;
            remind = numBottles % numExchange;
            numBottles /= numExchange;
        }
        return ans;
    }
};