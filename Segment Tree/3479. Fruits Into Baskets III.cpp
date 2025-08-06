// 2025/08/06
class Solution {
private:
    const int segTree_size = 400005; // 因為 segTree 的空間複雜度大約會是 input 範圍上限的四倍
    vector<int> baskets;
    vector<int> segTree;
public:
    void build_segment_tree(int now, int left, int right){
        if(left == right){
            segTree[now] = baskets[left];
            return;
        }
        int mid = (left + right) >> 1;
        build_segment_tree(now << 1, left, mid);
        build_segment_tree(now << 1 | 1, mid + 1, right);
        segTree[now] = max(segTree[now << 1], segTree[now << 1 | 1]); // now << 1 | 1 = (now * 2) + 1
    }
    int query_leftmost_interval(int now, int left, int right, int query_left, int query_right){
        if(query_left > right || query_right < left) return INT_MIN; // 設一個超小值，相當於此 basket 已被使用
        if(query_left <= left && query_right >= right) return segTree[now]; // 一直去調整 left 和 right 的範圍直到完全被 include 在 query_left ~ query_right 之間
        int mid = (left + right) >> 1;
        return max(query_leftmost_interval(now << 1, left, mid, query_left, query_right), query_leftmost_interval(now << 1 | 1, mid + 1, right, query_left, query_right));
    }
    void update_segment_tree(int now, int left, int right, int position, int value){
        if(left == right){
            segTree[now] = value; // 查找到這個 position(leftmost_basket idx) 區間，把他值設成超小值，更新此 basket 已被使用
            return;
        }
        int mid = (left + right) >> 1;
        if(position <= mid) update_segment_tree(now << 1, left, mid, position, value); // 我覺得要判斷這個 now << 1 位址是 seg tree 最難的地方，或是這就是公式硬記(?
        else update_segment_tree(now << 1 | 1, mid+1, right, position, value);
        segTree[now] = max(segTree[now << 1], segTree[now << 1 | 1]);
    }

    Solution() : segTree(segTree_size) {} // 偶爾複習一下 constructor 寫法唄
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        this->baskets = baskets; // 物件導向，this->指的是「class 裡的 baskets」，也就是賦予 class 內部的 baskets 物件來自外部的 baskets 物件的值
        if(baskets.size() == 0) return fruits.size();

        build_segment_tree(1, 0, baskets.size() - 1);

        int ans = 0;
        for(int i = 0; i < fruits.size(); ++i){ // 遍歷每個 fruits 有沒有機會有 leftmost_basket
            int left = 0, right = baskets.size() - 1, leftmost_basket = -1;
            while(left <= right){
                int mid = (left + right) >> 1;
                // 查找 0~mid 之間是否有任何 basket 放得下 fruit 有的話就要排除 (區間 segTree 裡面存的是該區間的最大值)
                if(query_leftmost_interval(1, 0, baskets.size() - 1, 0, mid) >= fruits[i]){ 
                    leftmost_basket = mid; // 因為現在是 0~mid 有 leftmost，所以先把 leftmost 設成 mid，若之後試 0~(mid-1) 沒有符合的 basket，代表 leftmost 就是 mid
                    right = mid - 1;
                }
                else left = mid + 1; // 0~mid 之間沒有放得下的 basket，因此 left 往右
            }
            if(leftmost_basket != -1 && baskets[leftmost_basket] >= fruits[i]){ // 如果真找到這個符合條件的 leftmost_basket
                update_segment_tree(1, 0, baskets.size() - 1, leftmost_basket, INT_MIN);
            }
            else ans++; // 這水果沒地方放啊，ans++ !
        }
        return ans;
    }
};