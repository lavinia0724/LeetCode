// 2025/07/15
class Solution {
public:
    bool isVowel(char a) {return string("aeiouAEIOU").find(a) != std::string::npos;}
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool check_vowel = false, check_consonant = false, is_digit_alpha = true;
        for(auto w: word){
            check_vowel = check_vowel | isVowel(w);
            check_consonant = check_consonant | (!isVowel(w) && isalpha(w));
            is_digit_alpha = is_digit_alpha && (isdigit(w) | isalpha(w));
        }
        return check_vowel && check_consonant && is_digit_alpha;
    }
};