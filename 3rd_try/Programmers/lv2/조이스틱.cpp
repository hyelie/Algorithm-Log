#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int get_leftmost_index(string temp){ // 왼쪽으로만 갈 때 어디까지 가야 하는지 index
    for(int i = 1; i<temp.length(); i++){ // idx 0은 시작 위치에서 바로 바꿀 수 있으니 skip
        if(temp[i] == '1') return i;
    }
    return -1;
}

int get_rightmost_index(string temp){ // 오른쪽으로만 갈 때 어디까지 가야 하는지 index
    for(int i = temp.length()-1; i>=0; i--){
        if(temp[i] == '1') return i;
    }
    return -1;
}

int solution(string name) {
    int len = name.length();
    
    // 위아래 회수
    int updown = 0;
    string temp = "";
    for(char c : name){
        updown += min(c - 'A', 'Z' - c + 1); // *** 실수 1. 위/아래 둘 다 할 수 있다.
        temp += (c == 'A' ? "0" : "1");
    }
    if(updown == 0) return 0;
    
    // 좌우 회수 조사
    // temp의 모든 위치에서 시작, 왼쪽 / 오른쪽 각각 진행, 각 temp에서는 몇번만에 temp까지 갈 수 있는지 앎.
    int answer = 1e9;
    for(int i = 0; i<len; i++){
        int leftmost = get_leftmost_index(temp);
        int rightmost = get_rightmost_index(temp);
        
        // 왼쪽으로만 가는 경우, 오른쪽으로만 가는 경우 greedy로.
        // *** 실수 2. 해당 위치까지 몇 번만에 갈 수 있는지 : min(i, len - i)를 더했어야 했다.
        answer = min(answer, min(rightmost, len - leftmost) + min(i, len - i));
        
        temp = temp.substr(1) + temp[0]; // 첫 번째 글자를 제일 뒤로 보냄, cyclic
    }
    
    return answer + updown;
}