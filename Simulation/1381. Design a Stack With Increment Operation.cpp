// 2024/09/30
class CustomStack {
public:
    list<int> stk;
    int capacity;
    
    CustomStack(int maxSize) {
        capacity = maxSize;
    }
    
    void push(int x) {
        if(stk.size() < capacity) stk.push_back(x);
    }
    
    int pop() {
        if (stk.empty()) return -1;
        int topElement = stk.back();
        stk.pop_back();
        return topElement;
    }
    
    void increment(int k, int val) {
        auto it = stk.begin();
        for(int i = 0; i < k && it != stk.end(); ++i, ++it){
            *it += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */