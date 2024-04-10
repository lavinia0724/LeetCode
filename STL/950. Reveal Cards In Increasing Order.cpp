/* 2024/04/10 */
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> index;
        vector<int> ans;

        for(int i = 0; i < deck.size(); ++i){
            index.emplace_back(i);
            ans.emplace_back(0);
        }

        /* initial
            deck = [2, 3, 5, 7, 11, 13, 17]
            ans = [0, 0, 0, 0, 0, 0, 0]
            index = [0, 1, 2, 3, 4, 5, 6]

            after first round
            ans = [2, 0, 0, 0, 0, 0, 0]
            index = [2, 3, 4, 5, 6, 1]

            after second round
            ans = [2, 0, 3, 0, 0, 0, 0]
            index = [4, 5, 6, 1, 3]
            ...
        */
        for(int i = 0; i < deck.size(); ++i){
            ans[index.front()] = deck[i];
            index.pop_front();
            index.emplace_back(index.front());
            index.pop_front();
        }
        return ans;
    }
};