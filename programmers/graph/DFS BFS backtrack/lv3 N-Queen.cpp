// N-Queen

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int answer = 0;
vector<int> queen_position;

bool canPlace(int r, int c){
    for(int i = 0; i<r; i++){
        if(queen_position[i] == c || r-i == abs(c-queen_position[i])) return false;
    }
    return true;
}

void DFS(int cur_depth, int max_depth){
    if(cur_depth == max_depth){
        answer++;
        return;
    }
    
    for(int i = 0; i<max_depth; i++){
        if(canPlace(cur_depth, i)){
            queen_position[cur_depth] = i;
            DFS(cur_depth+1, max_depth);
        }
    }
}

int solution(int n) {
     // queen_position[i] = x일 때 (i,x)에 있다는 것.
    vector<int> qp(n); queen_position = qp;
    DFS(0, n);
    
    return answer;
}

// queen은 줄에 1개씩 둘 수 있다. -> 층은 n개만 가능.