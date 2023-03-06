#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp1(vector<int> &a, vector<int>& b){ // a[0] 내림차순, b[0] 내림차순
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] > b[0];
}

bool cmp2(vector<int> &a, vector<int> &b){
    if(a[0] + a[1] == b[0] + b[1]){
        return a[0] > b[0];
    }
    if(a[0] + a[1] > b[0] + b[1]) return true;
    else return false;
}

int solution(vector<vector<int>> scores) {
    vector<int> target = scores[0];
    
    // 1차 : 못 받는 애들 다 자름
    sort(scores.begin(), scores.end(), cmp1);
    for(vector<int> score : scores){
        cout<<score[0]<<score[1]<<endl;
    }
    // first는 내림차순, second는 오름차순.
    // a, b가 있을 때 a.first > b.first는 보장됨
    // a.second > b.second면 둘 다 작은 거임. 그건 pass
    vector<vector<int>> sieve;
    int prevSecond = scores[0][1];
    for(int i = 0; i<scores.size(); i++){
        if(prevSecond > scores[i][1]){
            if(target[0] == scores[i][0] && target[1] == scores[i][1]) return -1;
            continue;
        }
        else{
            prevSecond = scores[i][1];
            sieve.push_back(scores[i]);
        }
    }
    
    // 2차 : 등수 매김
    sort(sieve.begin(), sieve.end(), cmp2);
    for(int i = 0; i<sieve.size(); i++){
        if(sieve[i][0] + sieve[i][1] == target[0] + target[1]) return i+1;
    }
    

    return -1;
}