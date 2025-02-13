// 2025/02/13
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end()); // 這樣 pq 才會由小到大
    
            int step = 0;
            while(pq.top() < k){
                int x = pq.top();
                pq.pop();
                step++;
            }
            return step;
        }
    };