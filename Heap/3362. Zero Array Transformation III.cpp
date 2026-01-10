// 2026/01/10
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(queries.begin(), queries.end()); // 按照 left 排序

        priority_queue<int> heap; // 存 right
        vector<int> diff(n + 2, 0);
        int cover = 0, j = 0;
        for (int i = 0; i < n; i++) {
            // cover 把 right 已覆蓋不到 nums[i] 的 query 數量加回去 (diff 必 <= 0)
            cover += diff[i];

            // 加入 left == i 的 query
            while (j < queries.size() && queries[j][0] == i) {
                heap.push(queries[j][1]);
                j++;
            }

            // 補足 nums[i] 需要的次數
            while (cover < nums[i]) {
                // 移除 right 已覆蓋不到 nums[i] 的 query
                while (!heap.empty() && heap.top() < i) heap.pop();
                // 如果 query 用完的，但 nums[i] 還沒歸零，代表無法有結果了
                if (heap.empty()) return -1;

                int right = heap.top();
                heap.pop();

                cover++;
                diff[right + 1]--;
            }
        }

        // 剩下的 query 都可以移除
        return heap.size();
    }
};