/* 2024/05/01 */
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int ptr = 0;
        for(int i = 0; i < word.size(); ++i){
            if(word[i] == ch){
                ptr = i;
                break;
            }
        }
        reverse(word.begin(), word.begin() + ptr + 1);
        return word;
    }
};