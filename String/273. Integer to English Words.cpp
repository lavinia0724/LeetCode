// 2024/08/07
class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";

        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        string ans = "";
        int idx = 0;

        while(num > 0){
            if(num % 1000 != 0){
                string nowPart = "";
                int backPart = num % 1000;

                if(backPart >= 100){
                    nowPart = ones[backPart / 100] + " Hundred ";
                    backPart %= 100;
                }

                if(backPart >= 20){
                    nowPart += tens[backPart / 10] + " ";
                    backPart %= 10;
                }

                if(backPart > 0){
                    nowPart += ones[backPart] + " ";
                }

                nowPart += thousands[idx] + " ";
                ans = nowPart + ans;
            }

            num /= 1000;
            idx++;
        }
        return ans.substr(0, ans.find_last_not_of(" ") + 1);
    }
};