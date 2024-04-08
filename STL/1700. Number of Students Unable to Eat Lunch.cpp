/* 2024/04/08 */
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int remainSandwiches = 0;
        while(remainSandwiches < students.size()){
            if(students.front() == sandwiches.front()){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                remainSandwiches = 0;
            }
            else{
                students.emplace_back(students.front());
                students.erase(students.begin());
                remainSandwiches++;
            }
        }
        if(remainSandwiches != 0) return remainSandwiches;
        else return 0;
    }
};