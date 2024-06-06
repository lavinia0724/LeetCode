// 2024/06/06
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> num;
        for(int i = 0; i < hand.size(); ++i){
            num[hand[i]]++;
        }

        auto ptr = num.begin();
        for(auto iter = num.begin(); iter != num.end(); ++iter){
            while(iter->second > 0){
                for(int i = 0; i < groupSize; ++i){
                    int now = iter->first + i;
                    if(num[now] <= 0) return false;
                    num[now] -= 1;
                }
            }
        }  

        return true;
    }
};