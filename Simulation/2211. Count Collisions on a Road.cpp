// 2025/12/04
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;

        // 略過最左的 L 和最右的 R 因為一定不會撞到
        while(left < n && directions[left] == 'L') left++;
        while(right >= 0 && directions[right] == 'R') right--;

        int ans = 0;
        for(int i = left; i <= right; ++i){
            if(directions[i] == 'L' || directions[i] == 'R') ans++;
        }
        return ans;
    }
};