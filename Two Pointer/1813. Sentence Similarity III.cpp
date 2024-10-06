// 2024/10/06
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size() > sentence2.size()) swap(sentence1, sentence2);

        deque<string> dq1, dq2;
        while (true) {
            // 取得最後一個字。最後一個字找不到空白了
            if (sentence1.find(" ") == -1) {
                dq1.push_back(sentence1);
                break;
            }

            dq1.push_back(sentence1.substr(0, sentence1.find(" "))); // 從第一個空白分割出左側子字串放入vector
            sentence1 = sentence1.substr(sentence1.find(" ") + 1, sentence1.size()); // 從第一個空白分割出右側子字串設為s
        }
        while (true) {
            if (sentence2.find(" ") == -1) {
                dq2.push_back(sentence2);
                break;
            }

            dq2.push_back(sentence2.substr(0, sentence2.find(" "))); 
            sentence2 = sentence2.substr(sentence2.find(" ") + 1, sentence2.size()); 
        }

        bool flag = false;
        while(!dq1.empty()){
            if(!flag){
                if(dq1.front() == dq2.front()){
                    dq1.pop_front();
                    dq2.pop_front();
                }
                else flag = true;
            }
            else{
                if(dq1.back() == dq2.back()){
                    dq1.pop_back();
                    dq2.pop_back();
                }
                else return false;
            }
        }
        return true;
    }
};