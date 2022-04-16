// 파일명 정렬

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 앞에게 더 크면(a가 더 크면) true.
bool comp(vector<string> a, vector<string> b){
    for(char &c : a[0]){
        c = tolower(c);
    }
    for(char &c : b[0]){
        c = tolower(c);
    }
    if(a[0] < b[0]) return true;
    else if(a[0] > b[0]) return false;
    
    int anum = stoi(a[1]), bnum = stoi(b[1]);
    if(anum < bnum) return true;
    else if(anum >= bnum) return false;
}

void swap(vector<string>& a, vector<string>& b){
    vector<string> temp(3);
    temp[0] = a[0]; temp[1] = a[1]; temp[2] = a[2];
    a[0] = b[0]; a[1] = b[1]; a[2] = b[2];
    b[0] = temp[0]; b[1] = temp[1]; b[2] = temp[2];
    return;
}

vector<string> solution(vector<string> files) {
    int size = files.size();
    vector<vector<string>> parsed(files.size(), vector<string>(3));
    for(int i = 0; i<size; i++){
        int file_idx = 0;
        while(!isdigit(files[i][file_idx])){
            file_idx++;
        }
        parsed[i][0] = files[i].substr(0, file_idx);
        
        int number_len = 0;
        while(file_idx < files[i].size() && isdigit(files[i][file_idx]) && number_len < 5){
            number_len++;
            file_idx++;
        }
        parsed[i][1] = files[i].substr(file_idx - number_len, number_len);
        parsed[i][2] = files[i].substr(file_idx);
    }
    
    stable_sort(parsed.begin(), parsed.end(), comp);
    
    vector<string> answer(size);
    for(int i = 0; i<size; i++){
        answer[i] = parsed[i][0] + parsed[i][1] + parsed[i][2];
    }
    return answer;
}

/*

파일명 - 영어 소문자, 영어 대문자, 숫자, " ", ".", "-"로 이루어짐.
head : 숫자가 아닌 문자. 대소문자는 구별하지 않음.
number : 1~5 사이의 연속된 숫자로 이루어짐. 앞쪽에 0이 올 수 있음. head가 같을 경우 숫자 순으로 정렬.
tail : 나머지 부분. 숫자가 올 수도 있고, 아무 글자 없을 수도 있다.
head와 number가 같을 경우 stable sort를 유지해야 함.
파싱이 관건이네

*/