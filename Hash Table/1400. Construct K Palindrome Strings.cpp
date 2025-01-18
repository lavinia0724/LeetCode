// 2025/01/11
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false; // 絕對組不出來
        if(s.size() == k) return true; // 把 s 的每個字母都獨立成一個 string，必有 k 個

        int alphabetCnt[26] = {0};

        for(int i = 0; i < s.size(); ++i) alphabetCnt[s[i] - 'a']++;
        
        int oddFreqCnt = 0;
        for(int i = 0; i < 26; ++i){
            if(alphabetCnt[i] & 1) oddFreqCnt++;
        }

        // 因為所有偶數頻率的字母都可拆也可組在一起，所以只判斷奇數頻率的字母的數量就好
        // 當奇數頻率的字母的數量 == k，那所有偶數頻率的字母都和某個奇數頻率的字母組一起就好，然後其他奇數字母各為一個 string
        // 當奇數頻率的字母的數量 < k，不足 k 的部份由偶數頻率的字母去組
        if(oddFreqCnt <= k) return true;
        return false;
    }
};