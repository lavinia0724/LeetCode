// 2025/12/24
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int total = accumulate(apple.begin(), apple.end(), 0);

        int cnt = 0;
        for(int i = 0; i < capacity.size(); ++i){
            cnt += capacity[i];
            if(cnt >= total) return i + 1;
        }
        return capacity.size();
    }
};