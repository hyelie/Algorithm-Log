// 문자열 내 마음대로 정렬하기

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx;

bool comp(string a, string b){
    if(a[idx] == b[idx]) return a<b;
    else return a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}