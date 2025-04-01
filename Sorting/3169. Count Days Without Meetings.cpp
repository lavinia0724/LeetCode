// 2025/03/24
class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            unordered_map<int, int> schedule;
            priority_queue<int, vector<int>, greater<int>> pq;
            for(auto item: meetings) {
                if(schedule.count(item[0]) != 0) schedule[item[0]] = max(schedule[item[0]], item[1]);
                else schedule[item[0]] = item[1];
                pq.push(item[0]);
            }
            
            int freeDay = 0, maxiDay = 0;
            while(!pq.empty()){
                int day = pq.top();
                pq.pop();
                if(day > maxiDay) freeDay += day - maxiDay - 1;
                if(schedule.count(day) != 0){
                    maxiDay = max(maxiDay, schedule[day]);
                }
                else{
                    if(maxiDay < day) freeDay++;
                }
            }
            return freeDay + (days - maxiDay);
        }
    };