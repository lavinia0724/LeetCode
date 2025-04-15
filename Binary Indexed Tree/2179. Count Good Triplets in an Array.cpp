// 2025/04/15
class BinaryIndexedTree {
    public:
        BinaryIndexedTree(int size): tree(size+1, 0){}
    
        void update(int idx, int delta){
            idx++;
            // 在第 idx 個位置加上 delta，然後把所有受到影響的節點也更新
            while(idx < tree.size()){
                tree[idx] += delta;
                idx += idx & -idx; // idx & -idx: 獲取idx二進制表示中最低位的1
            }
        }
    
        int query(int idx){
            idx++;
            int res = 0;
            // 傳回 0~idx 之間的總和
            while(idx > 0){
                res += tree[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    
    private:
        vector<int> tree;
    };
    
    class Solution {
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            // idxMapping 是紀錄 nums1 的值存在 nums2 的哪個位置
            vector<int> position2(nums2.size()), idxMapping(nums2.size()); 
            for(int i = 0; i < nums2.size(); ++i) position2[nums2[i]] = i;
            for(int i = 0; i < nums2.size(); ++i) idxMapping[position2[nums1[i]]] = i;
    
            BinaryIndexedTree tree(nums1.size());
            long long res = 0;
            for(int val = 0; val < nums1.size(); val++){
                int pos = idxMapping[val];
                int left = tree.query(pos);
    
                tree.update(pos, 1);
    
                int right = (nums1.size() - 1 - pos) - (val - left);
                res += (long long)left * right;
            }
            return res;
        }
    
    };