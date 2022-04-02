// 조이스틱

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int calDist(char input){
    return min(input - 'A', 'Z' - input + 1);
}

int solution(string name) {
    if(name == "") return 0;
    int left, right, answer = 2000000000, length = name.length();
    string temp;
    // string 제일 앞에 있는 걸 뒤로 1개씩 밀면서 min value 탐색
    for(int i = 0; i<length; i++){
        temp = name.substr(i, length - i) + name.substr(0, i);
        // temp : 초기 name으로부터 i개의 문자를 뒤로 민 문자열

        left = right = 0;
        // left : temp에서 왼쪽으로 이동시켰을 때 마지막까지 이동시키면 되는 idx
        for(int idx = 1; idx < length; idx++){
            if(temp[idx] != 'A'){
                left = idx;
                break;
            }
        }
        left = length - left;
        // right : temp에서 오른쪽으로 이동시켰을 때 마지막까지 이동시키면 되는 idx
        for(int idx = length-1; idx > 0; idx--){
            if(temp[idx] != 'A'){
                right = idx;
                break;
            }
        }
        // cout<<"temp : "<<temp<<" | l, r : "<<left<<" "<<right<<" | 이동 : "<<min(i, length-i)<<endl;
        
        // min(i, length - i); // 초기 name으로부터 i개의 문자를 민 temp까지 최소 이동 횟수
        answer = min(answer, min(i, length-i) + min(left, right));
    }
    
    int differ = 0;
    for(int i = 0; i<length; i++){
        differ += calDist(name[i]);
    }
    
    return answer + differ;
}

// JAN
// 9 0 13
// 
// BABAAAAABAB 이런 경우를 보자
// 2 1     4 3 이게 최선일 것임. 답 11, (가로이동 7)
// 그러니까
// 모든 문자열 1번씩 순회하면서(길이 20이니 충분) 양쪽으로 방향만 보면 될 것.
// ABAAAAABABB 기본 1 + min(10(오른족), 10)
// BAAAAABABBA 기본 2 + min(5(왼쪽), 9)
// AAAAABABBAB 기본 3 + 
// 이런 식으로 세 갈것임.
// 그러면 더이상 가지 않아도 되는 건 어떻게 아느냐...
// 오른쪽으로 가는 경우, idx 0 기준 A가 아닌 문자열의 오른쪽 끝을 찾으면 되고
// 왼쪽으로 가는 경우, idx 0 기준 왼쪽으로 가서 A가 아닌 문자열의 끝을 찾으면 될 것임.
// JAN : 0번 + 1번
// ANJ : 1번 + 2번
// NJA : 1번 + 1번


// ABABAAAAAAABA
// 7 + 3 = 10