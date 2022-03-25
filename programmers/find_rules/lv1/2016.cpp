#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<int> days_in_month = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> days_in_week = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int day_cnt = b-1;
    for(int i = 1; i<a; i++){
        day_cnt += days_in_month[i];
    }
    
    return days_in_week[day_cnt%7];
}