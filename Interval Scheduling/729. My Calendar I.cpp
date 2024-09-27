// 2024/09/27
class MyCalendar {
public:
    map<int, int>  bookingCnt;
    MyCalendar() { }
    
    bool book(int start, int end) {
        bookingCnt[start]++;
        bookingCnt[end]--;

        int bookingPrefix = 0;
        for(auto [idx, bookingNum]: bookingCnt){
            bookingPrefix += bookingNum;

            if(bookingPrefix > 1){
                bookingCnt[start]--;
                bookingCnt[end]++;

                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */