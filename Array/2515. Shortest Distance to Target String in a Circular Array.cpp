// 2026/04/15
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int mini = INT_MAX;
        for(int i = 0; i < n; ++i){
            if(words[i] == target) mini = min(mini, min(abs(i - startIndex), n - abs(i - startIndex)));
        }
        return (mini == INT_MAX) ? -1 : mini;
    }
};