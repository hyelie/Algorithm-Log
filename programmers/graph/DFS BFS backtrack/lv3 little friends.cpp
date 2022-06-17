// 리틀 프렌즈 사천성

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;

bool checkRow(int rfrom, int rto, int c, int cha, vector<string>& boards){
    int end = max(rfrom, rto), start = min(rfrom, rto);
    for(int r = start; r<=end; r++){
        if(boards[r][c] == cha || boards[r][c] == '.') continue;
        return false;
    }
    return true;
}

bool checkCol(int cfrom, int cto, int r, int cha, vector<string>& boards){
    int end = max(cfrom, cto), start = min(cfrom, cto);
    for(int c = start; c<=end; c++){
        if(boards[r][c] == cha || boards[r][c] == '.') continue;
        return false;
    }
    return true;
}

// c : 시작/도착 글자
// from/to : 출발/도착 좌표
bool canReach(pii from, pii to, char c, vector<string>& boards){
    if(checkRow(from.first, to.first, from.second, c, boards) && checkCol(from.second, to.second, to.first, c, boards)) return true;
    if(checkRow(from.first, to.first, to.second, c, boards) && checkCol(from.second, to.second, from.first, c, boards)) return true;
    return false;
}

string backtrack(int cur_depth, int max_depth, vector<vector<pii>>& word_coordinate, vector<bool>& visited, string cur_str, vector<string>& boards){
    string answer = "";
    if(cur_depth == max_depth && answer == "IMPOSSIBLE"){
        answer = cur_str;
        return answer;
    }
    
    for(int i = 0; i<word_coordinate.size(); i++){
        if(visited[i]) continue;
        pii from = word_coordinate[i][0];
        pii to = word_coordinate[i][1];
        char cur_char = boards[from.first][from.second];
        if(canReach(from, to, cur_char, boards)){
            visited[i] = true;
            boards[from.first][from.second] = '.';
            boards[to.first][to.second] = '.';
            answer += cur_char;
            i = -1;
        }
    }
    
    bool flag = true;
    for(bool b : visited){
        if(b == false) flag = false;
    }
    if(flag == false) answer = "IMPOSSIBLE";
    
    
    return answer;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    map<char, vector<pii>> mapper;
    for(int r = 0; r<m; r++){
        for(int c = 0; c<n; c++){
            if(board[r][c] == '*' || board[r][c] == '.') continue;
            mapper[board[r][c]].push_back({r, c});
        }
    }
    
    vector<vector<pii>> word_coordinate;
    for(auto [k, v] : mapper){
        word_coordinate.push_back(v);
    } // word_coordinate[i][0] : 첫 좌표, [1] : 두번째 좌표. word_coordinate는 오름차순 정렬.
    vector<bool> visited(word_coordinate.size(), false);
    
    return backtrack(0, word_coordinate.size(), word_coordinate, visited, "", board);
    
    
    
}

/*
경로가 1번 꺾여야 함은 어떻게 알까?
무조건 ㄱ 또는 ㄴ자가 되어야 한다. 그 경로에 다른 무언가가 있다면 없애지 못하는 것.
*/