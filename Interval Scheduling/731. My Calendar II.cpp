// 2024/09/27
class MyCalendarTwo {
public:
    map<int, int>  bookingCnt;
    MyCalendarTwo() {　}
    
    bool book(int start, int end) {
        bookingCnt[start]++;
        bookingCnt[end]--;

        int bookingPrefix = 0;
        for(auto [idx, bookingNum]: bookingCnt){
            bookingPrefix += bookingNum;

            if(bookingPrefix > 2){
                bookingCnt[start]--;
                bookingCnt[end]++;

                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

/*
bookingCnt
intert interval [3, 8]
0 1 2 3 4 5 6 7 8  9 
0 0 0 1 0 0 0 0 -1 0

find bookingPrefix ---- true

intert interval [4, 6]
0 1 2 3 4 5 6  7  8 9 
0 0 0 1 1 0 -1 0 -1 0

find bookingPrefix
0 1 2 3 4 5 6 7 8 9 
0 0 0 1 2 0 1 1 0 0
---- true

intert interval [1, 6]
0 1 2 3 4 5 6  7  8 9 
0 1 0 1 1 0 -2 0 -1 0

find bookingPrefix
0 1 2 3 4 5 6 7 8 9 
0 1 1 2 3 0 1 1 0 0
---- false! because idx:4 = 3
*/