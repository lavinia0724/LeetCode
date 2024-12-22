// 2024/12/22
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> targetTime = times[targetFriend];
        sort(times.begin(), times.end());

        int n = times.size();
        vector<int> chairLeavingTime(times.size());

        for (auto time : times) {
            for (int i = 0; i < times.size(); i++) {
                if (chairLeavingTime[i] <= time[0]) {
                    chairLeavingTime[i] = time[1];
                    if (time == targetTime) return i;
                    break;
                }
            }
        }
        return 0;
    }
};