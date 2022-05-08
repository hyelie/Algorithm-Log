// 하노이의 탑

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void move(int from, int temp, int to, int size){
    if(size == 1){
        answer.push_back({from, to});
        return;
    }
    
    move(from, to, temp, size-1);    
    answer.push_back({from, to});
    move(temp, from, to, size-1);
}

vector<vector<int>> solution(int n) {
    move(1, 2, 3, n);
    return answer;
}