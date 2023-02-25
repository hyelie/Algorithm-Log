#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> m; // [성격 유형]의 [점수] mapper
vector<string> order = {"RT", "CF", "JM", "AN"};

// survey와 choice가 주어졌을 때 해당하는 type에 점수를 추가
void addPointToType(string survey, int choice){
    if(choice < 4){ //앞
        m[survey[0]] += 4 - choice;
    }
    else if(choice > 4){ // 뒤
        m[survey[1]] += choice - 4;
    }
    // else then nothing
    // if empty map, then int value must set by 0
}

// m에 저장된 정보로 i번째 type을 리턴
char getIthType(int i){
    char first = order[i][0], second = order[i][1];
    if(m[first] >= m[second]){
        return first;
    }
    else return second;
}

// 해당 사용자의 type을 리턴
string getType(){
    string result = "";
    for(int i = 0; i<4; i++){
        result += getIthType(i);
    }
    return result;
}

string solution(vector<string> surveys, vector<int> choices) {
    int n = surveys.size();
    for(int i = 0; i<n; i++){
        addPointToType(surveys[i], choices[i]);
    }
    return getType();
}