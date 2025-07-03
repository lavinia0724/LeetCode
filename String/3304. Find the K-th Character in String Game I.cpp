// 2025/07/03
class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size() < k){
            string tmp = "";  
            for(char alphabet: word){
                tmp += alphabet + 1;
            }
            word += tmp;
        }
        return word[k-1];
    }
};