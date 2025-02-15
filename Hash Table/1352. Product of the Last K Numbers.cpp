// 2025/02/14
class ProductOfNumbers {
    public:
        ProductOfNumbers() { 
            productTable.push_back(1);
        }
        
        void add(int num) {
            if(num == 0){
                productTable.clear();
                productTable.push_back(1);
            }
            else productTable.push_back(productTable.back() * num);
        }
        
        int getProduct(int k) {
            if(k > productTable.size() - 1) return 0;
            return productTable.back() / productTable[productTable.size() - 1 - k];
        }
    
    private:
        vector<long long int> productTable;
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */