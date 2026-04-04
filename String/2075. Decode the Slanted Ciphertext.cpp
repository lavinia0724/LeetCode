// 2026/04/04
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 0) return "";

        int cols = n / rows;
        string result;

        for (int startCol = 0; startCol < cols; startCol++) {
            int r = 0, c = startCol;

            while (r < rows && c < cols) {
                result.push_back(encodedText[r * cols + c]);
                r++;
                c++;
            }
        }

        // 移除 trailing spaces
        while (!result.empty() && result.back() == ' ') result.pop_back();

        return result;
    }
};