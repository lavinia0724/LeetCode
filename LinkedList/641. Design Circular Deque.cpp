// 2024/09/28
struct Node{
    int val;
    Node* next;
    Node* prev;
};

class MyCircularDeque {
public:
    Node* head;
    Node* rear;
    int size;
    int capacity;

    MyCircularDeque(int k) {
        head = NULL;
        rear = NULL;
        size = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(head == NULL) {
            head = new Node(value);
        }
        else{
            Node* now = new Node(value);
            now->val = value;
            now->next = head;
            head->prev = now;

            if(rear == NULL) rear = head;
            head = now;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(head == NULL) {
            head = new Node(value);
        }
        else{
            Node* now = new Node(value);

            if(rear == NULL) {
                head->next = now;
                now->prev = head;
            }
            else{
                rear->next = now;
                now->prev = rear;
            }

            rear = now;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        if(size == 1){
            head = NULL;
            rear = NULL;
        }
        else head = head->next;

        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        
        if(size == 1){
            head = NULL;
            rear = NULL;
        }
        else rear = rear->prev;

        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return head->val;
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        if(rear == NULL) return head->val;
        return rear->val;
    }
    
    bool isEmpty() {
        if(size == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(size == capacity) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */