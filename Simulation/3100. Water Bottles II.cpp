// 2025/10/02
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fullBottles = numBottles, emptyBottles = 0, bottlesDrunk = 0;
        while(fullBottles > 0){
            bottlesDrunk += fullBottles;
            emptyBottles += fullBottles;
            fullBottles = 0;
            while(emptyBottles >= numExchange){
                fullBottles++;
                emptyBottles -= numExchange;
                numExchange++;
            }
        }
        return bottlesDrunk;
    }
};