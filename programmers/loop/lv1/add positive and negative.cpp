// 음양 더하기

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int sum = 0, size = absolutes.size();
    for(int i = 0; i<size; i++){
        sum += absolutes[i] * (signs[i] ? 1 : -1);
    }
    return sum;
}