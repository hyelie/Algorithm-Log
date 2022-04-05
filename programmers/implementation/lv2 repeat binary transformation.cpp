// 이진 변환 반복하기

#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int num_zero = 0;

string toBinary(string s){
    int num_one = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '0') num_zero++;
        else num_one++;
    }
    string result = "";
    while(num_one){
        result = to_string(num_one%2) + result;
        num_one /= 2;
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while(s != "1"){
        s = toBinary(s);
        answer[0]++;
    }
    answer[1] = num_zero;
    return answer;
}