#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
int UNUSED = -1;
vector<int> arr(12, UNUSED);

bool can_place(int r, int c){ // r, c에 두는 경우
    for(int i = 0; i<r; i++){
        if(arr[i] == c) return false;
        if(abs(r - i) == abs(c - arr[i])) return false;
    }
    return true;
}

void backtrack(int cur_depth, int max_depth){
    if(cur_depth == max_depth){
        answer++;
        return;
    }
    
    for(int i = 0; i<max_depth; i++){
        if(can_place(cur_depth, i)){
            arr[cur_depth] = i;
            backtrack(cur_depth+1, max_depth);
        }
    }
}

int solution(int n) {
    backtrack(0, n);
    return answer;
}