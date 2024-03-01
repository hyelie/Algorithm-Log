#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef vector<int> vi;
bool comp(vi &a, vi &b){
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), comp);
    
    int answer = 1, view = routes.front()[1];
    
    for(vi &route : routes){
        int start = route[0], end = route[1];
        
        if(start <= view && view <= end) continue;
        answer++;
        view = end;
    }
    
    return answer;
}