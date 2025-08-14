// 2025/08/14
class Solution {
public:
    string largestGoodInteger(string num) {
        string goodstr[] = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};
        for(auto good: goodstr)
            if(num.find(good) != string::npos) return good;
        return "";
    }
};