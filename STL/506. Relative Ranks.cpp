/* 2024/05/08 */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> rank;
        for(int i = 0; i < score.size(); ++i){
            rank.push_back({score[i], i});
        }
        sort(rank.rbegin(), rank.rend());

        vector<string> ans(score.size());
        for(int i = 0; i < rank.size(); ++i){
            string place = to_string(i+1);
            if(place == "1") place = "Gold Medal";
            else if(place == "2") place = "Silver Medal";
            else if(place == "3") place = "Bronze Medal";
            ans[rank[i].second] = place;
        }
        return ans;
    }
};