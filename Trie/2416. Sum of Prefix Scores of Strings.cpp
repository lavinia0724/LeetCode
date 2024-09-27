// 2024/09/25
struct TrieNode {
    TrieNode* next[26] = {};
    int cnt = 0;
};

class Solution {
    TrieNode root;
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i){
            auto node = &root;
            for(char character: words[i]){
                if(!node->next[character - 'a']){
                    node->next[character - 'a'] = new TrieNode();
                }

                node->next[character - 'a']->cnt += 1;
                node = node->next[character - 'a'];
            }
        }

        vector<int> ans(words.size(), 0);
        for(int i = 0; i < words.size(); ++i){
            auto node = &root;
            ans[i] = 0;
            for(char character: words[i]){
                ans[i] += node->next[character - 'a']->cnt;
                node = node->next[character - 'a'];
            }
        }

        return ans;
    }
};

/*
words = ["abc","ab","bc","b"]
TrieNode:
"abc": (a, 1) -> (b, 1) -> (c, 1)
"ab": (a, 2) -> (b, 2)
"bc": (b, 1) -> (c, 1)
"b": (b, 2)

so:
(a, 2) -> (b, 2) -> (c, 1)
(b, 2) -> (c, 1)

ans:
"abc" = 2 + 2 + 1 = 5
"ab" = 2 + 2 = 4
"bc" = 2 + 1 = 3
b = 2
*/ 