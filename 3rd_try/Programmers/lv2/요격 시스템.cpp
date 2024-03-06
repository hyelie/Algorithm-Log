#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

bool comp(vi &a, vi &b){ // 뒷자리 오름차순
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
} 

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), comp);
    
    double cur = targets[0][1] - 0.1;
    int answer = 1;
    for(int i = 1; i<targets.size(); i++){
        double start = targets[i][0], end = targets[i][1];
        if(start <= cur && cur <= end) continue;
        cur = end - 0.1;
        answer++;
        // if(targets[i][0] > cur){
        //     cur = targets[i][1] - 0.1;
        //     answer++;
        // }
    }
    
    
    return answer;
}