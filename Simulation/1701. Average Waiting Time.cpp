// 2024/07/09
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0.0;
        int lastFinishTime = 0;
        for(int i = 0; i < customers.size(); ++i){
            if(lastFinishTime < customers[i][0]) lastFinishTime = customers[i][0];
            ans += (lastFinishTime + customers[i][1] - customers[i][0]);
            lastFinishTime += customers[i][1];
        }
        ans /= customers.size();
        return ans;
    }
};