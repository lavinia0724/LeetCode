// 2025/03/30
class Solution {
    public:
        long long countOfSubstrings(string word, int k) {
            return atLeastK(word, k) - atLeastK(word, k + 1);
        }
    private:
        long long atLeastK(string word, int k){
            unordered_map<char, int> vowel;
            long long int ans = 0;
            int left = 0, consonantCnt = 0;
            for(int right = 0; right < word.size(); ++right) {
                
                if(isVowel(word[right])) vowel[word[right]]++;
                else consonantCnt++;
                
                while(vowel.size() == 5 && consonantCnt >= k){
                    ans += (word.size() - right); // 一定會加爆，但沒關係，就多加
                    // 因為現在是在多算，假設從現在這個 right 的 idx 之後的右邊全部都是母音的情況
                    // 然後等 atLeastK(word, k + 1) 的時候，因為 k+1 所以他會在 consonantCnt >= k+1 的時候才進來這個迴圈，然後開始多加
                    // 因此 atLeastK(word, k) - atLeastK(word, k + 1) 可以獲得 k 真正的數量有多少，因為會 - 假設錯誤，在 k+1 進來這個迴圈後的 right 後多加的量
    
                    if(isVowel(word[left])){
                        vowel[word[left]]--;
                        if(vowel[word[left]] == 0) vowel.erase(word[left]);
                    }
                    else consonantCnt--;
                    left++;
                }
            }
            
            return ans;
        }
        
    private:
        bool isVowel(char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }
    };