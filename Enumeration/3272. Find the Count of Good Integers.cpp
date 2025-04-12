// 2025/04/12
class Solution {
    public:
        void generatePalindromes(string& strnow, int idx, vector<string>& kpalstrings, int k){
            if(idx >= (strnow.size() + 1) / 2){
                if(stoll(strnow) % k == 0) kpalstrings.emplace_back(strnow);
                return;
            }
    
            if(idx != 0){ // 頭不能是 0 特別處理
                strnow[idx] = '0';
                strnow[strnow.size() - 1 - idx] = '0';
                generatePalindromes(strnow, idx + 1, kpalstrings, k);
            }
    
            for(char c = '1'; c <= '9'; c++){ // 其他 1~9 的組合
                strnow[idx] = c;
                strnow[strnow.size() - 1 - idx] = c;
                generatePalindromes(strnow, idx + 1, kpalstrings, k);
            }
        }
    
        long long countGoodIntegers(int n, int k) {
            vector<string> kpalstrings;
            string baseStr(n, '0'); // 長度為 n 的都是 0 的 string
            generatePalindromes(baseStr, 0, kpalstrings, k);
    
            set<string> frequencyPattern;
    
            for(auto str: kpalstrings){
                vector<int> frequency(10, 0); // 算每個 string 中 0~9 出現的頻率
                for(char c: str) frequency[c - '0']++;
                
                string pattern;
                for(auto freq: frequency) pattern += char('0' + freq); // 組成每個數字的頻率的字串 pattern
                frequencyPattern.insert(pattern);
            }
    
            long long Nfactorial = factorial(n); // 先算出 n 階
            long long total = 0;
    
            for(auto pattern: frequencyPattern){
                long long perm = Nfactorial;
                for(char f: pattern) perm /= factorial(f - '0');
    
                if(pattern[0] != '0'){
                    int zeros = pattern[0] - '0' - 1;
                    long long zeroPerm = factorial(n - 1);
                    for(int j = 1; j < pattern.size(); ++j) zeroPerm /= factorial(pattern[j] - '0');
                    zeroPerm /= factorial(zeros);
                    perm -= zeroPerm;
                }
                total += perm;
            }
            return total;
        }
    
        long long factorial(int num){
            long long numfactorial = 1;
            for(int i = 1; i <= num; ++i) numfactorial *= i;
            return numfactorial;
        }
    };