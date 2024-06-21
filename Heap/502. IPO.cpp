// 2024/06/22
class Solution {
    public:
        
        struct Project{
            int profit;
            int capital;

            // 由小到大
            bool const operator < (Project &item) const{
                return capital < item.capital;
            }
        };
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            int n = profits.size();
            Project projects[n];

            for(int i = 0; i < n; ++i){
                projects[i].profit = profits[i];
                projects[i].capital = capital[i];
            }
            sort(projects, projects + n);

            int cnt = 0;
            int ansCapital = w;
            priority_queue<int> pq;
            for(int i = 0; i < k; ++i){
                while(cnt < n && projects[cnt].capital <= ansCapital){
                    pq.push(projects[cnt].profit);
                    cnt++;
                }

                if(pq.empty()) break;

                ansCapital += pq.top();
                pq.pop();
            }

            return ansCapital;
        }
};