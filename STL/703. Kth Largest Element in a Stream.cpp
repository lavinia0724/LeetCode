// 2024/08/12
class KthLargest {
public:
    vector<int> v;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) v.emplace_back(num);
        sort(v.begin(), v.end());
    }
    
    int add(int val) {
        auto it = upper_bound(v.begin(), v.end(), val);
        v.insert(it, val);
        return v[v.size() - k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */