// 2025/05/28
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for(string word: words) mp[word]++;

        int cnt = 0, PalindromeInMiddle = 0;
        for(auto& [word, freq]: mp){
            string revstr = word;
            reverse(revstr.begin(), revstr.end());

            if(word == revstr){
                cnt += (freq / 2) * 4; // ex: 加上 aaaa (length + 4)，兩組 aa 可以加上 2/2 * 4 的長度
                if(freq % 2) PalindromeInMiddle = 1; // 如果 aa 有奇數組，可以把 aa 加在中間，但這種情況最多只有一次所以 = 1
            }
            else if(word < revstr && mp.count(revstr)){ // 這裡 word < revstr 只是為了防 ab ba 兩個算兩次
                cnt += min(freq, mp[revstr]) * 4; // 其他 ab ba 這種狀況，
            }
        }
        return cnt + PalindromeInMiddle * 2; // aa 長度 2 放中間所以 * 2
    }
};