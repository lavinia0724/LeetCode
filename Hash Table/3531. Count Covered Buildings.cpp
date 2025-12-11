// 2025/12/11
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();

        // row: x -> 最小 y, 最大 y
        unordered_map<int, int> leftMost, rightMost;
        // column: y -> 最小 x, 最大 x
        unordered_map<int, int> upMost, downMost;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            
            // 如果我的左邊沒有 building，那我的 leftMost 就是我自己的 y
            if (!leftMost.count(x)) leftMost[x] = y;
            else leftMost[x] = min(leftMost[x], y); // 如果有 building，那就看我和他的 y 誰小
            
            // 同理，看右邊有沒有 building
            if (!rightMost.count(x)) rightMost[x] = y;
            else rightMost[x] = max(rightMost[x], y); // 如果有 building，那就看我和他的 y 誰大
            
            // 同理，看上面有沒有 building
            if (!upMost.count(y)) upMost[y] = x;
            else upMost[y] = min(upMost[y], x);
            
            // 同理，看下面有沒有 building
            if (!downMost.count(y)) downMost[y] = x;
            else downMost[y] = max(downMost[y], x);
        }

        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            
            bool hasLeft  = leftMost[x] < y;
            bool hasRight = rightMost[x] > y;
            bool hasUp    = upMost[y] < x;
            bool hasDown  = downMost[y] > x;
            
            // 我的上下左右都一定要有一個 building，而且不能是我自己
            if (hasLeft && hasRight && hasUp && hasDown) ans++;
        }
        return ans;
    }
};