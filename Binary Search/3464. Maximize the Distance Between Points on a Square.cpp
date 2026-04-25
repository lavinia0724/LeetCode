// 2026/04/25
class Solution {
public:
    bool check(long long d, vector<long long>& pos, int k, long long perimeter) {
        int n = pos.size();
        // circular array：複製一圈
        vector<long long> arr = pos;
        for (int i = 0; i < n; ++i) arr.push_back(pos[i] + perimeter);

        // 枚舉每個點當第一個選的點
        for (int start = 0; start < n; ++start) {
            long long first = arr[start];
            long long last = first;
            int cnt = 1;

            // greedy：每次找下一個 >= last + d 的點
            int idx = start + 1;

            while (cnt < k) {
                auto it = lower_bound(arr.begin() + idx, arr.begin() + start + n, last + d);
                if (it == arr.begin() + start + n) break;

                last = *it;
                idx = it - arr.begin() + 1;
                cnt++;
            }

            // 選滿 k 個後，還要確認最後一個點繞回第一個點距離也 >= d
            if (cnt == k && perimeter - (last - first) >= d) return true;
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        long long perimeter = 4LL * side;
        vector<long long> pos;
        for (auto& p : points) {
            long long x = p[0], y = p[1];

            if (y == 0) pos.push_back(x);
            else if (x == side) pos.push_back(side + y);
            else if (y == side) pos.push_back(2LL * side + (side - x));
            else pos.push_back(3LL * side + (side - y));
        }

        sort(pos.begin(), pos.end());

        int ans = 0, n = points.size();
        long long left = 0, right = 2 * side;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(check(mid, pos, k, perimeter)){
                ans = mid;
                left = mid + 1; // 但想要的是最大的 k 裡的最小的 Manhattan distance
            }
            else right = mid - 1; 
        }
        return ans;
    }
};