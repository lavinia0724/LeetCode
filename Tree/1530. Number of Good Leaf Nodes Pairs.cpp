// 2024/07/18
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> dfs(TreeNode* now, int distance){
        // 如果是葉節點
        // 因為 left 和 right 的型態都是 TreeNode *，所以用 !now->left 才能判斷，神秘
        if(!now){
            return vector<int> (12);
        }
        else if(!now->left && !now->right){
            vector<int> nowChildDistanceCount(12);
            nowChildDistanceCount[0] = 1; // idx = 0, 因為葉節點到達自己的距離 = 0
            return nowChildDistanceCount;
        }


        vector<int> leftChild = dfs(now->left, distance);
        vector<int> rightChild = dfs(now->right, distance);

        vector<int> nowChildDistanceCount(12);

        // 根據題目，樹高不會超過 10 層，distance 也不會
        // 我的左子樹小孩和右子樹小孩中，從葉節點到達這些小孩的距離有多少
        // 我因為是前一個小孩再往上推一層的父親，所以我 +1 層的 nowChildDistanceCount[i+1] 就是我第 i 層的兩邊小孩加總
        for(int i = 0; i < 10; ++i){
            nowChildDistanceCount[i+1] = leftChild[i] + rightChild[i];
        }
        
        // index = 11 都用來存 "當前左右子樹的所有小孩中，兩個葉節點小孩路徑 <= distance 的數量"
        for(int dist1 = 0; dist1 <= distance; ++dist1){
            for(int dist2 = 0; dist2 <= distance; ++dist2){
                // 加 2 是加上從父親到左右小孩的各一步距離
                if(2 + dist1 + dist2 <= distance){
                    // 把所有該父親的小孩中，distance 兩邊子樹相加 (再+2) 小於 distance 的小孩組合都加總存於第 11 格
                    // 用乘的是因為假設左子樹葉節點小孩有一個，右子樹葉節點小孩有兩個，都符合 <= distance
                    // 那其實是 1 * 2，共有 2 對組合可以成立
                    nowChildDistanceCount[11] += leftChild[dist1] * rightChild[dist2];
                }
            }
        }
        
        // 將所有左子樹和右子樹過去符合的組合數也加入
        nowChildDistanceCount[11] += leftChild[11] + rightChild[11];

        return nowChildDistanceCount;
    }
    int countPairs(TreeNode* root, int distance) {
        return dfs(root, distance)[11];
    }
};