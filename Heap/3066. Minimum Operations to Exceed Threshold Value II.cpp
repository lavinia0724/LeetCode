// 2025/02/13
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long int, vector<long long int>, greater<long long int>> pq; // 這樣 pq 才會由小到大
            for(auto item: nums) pq.push(item);
    
            int step = 0;
            while(pq.top() < k){
                long long int x = pq.top();
                pq.pop();
                long long int y = pq.top();
                pq.pop();
    
                pq.push(min(x, y) * 2 + max(x, y));
                step++;
            }
            return step;
        }
    };