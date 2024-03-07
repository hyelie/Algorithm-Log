#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp1(vector<int> &v1, vector<int> &v2){ // 0번 내림차, 1번 오름차
    if(v1[0] == v2[0]){
        return v1[1] < v2[1];
    }
    return v1[0] > v2[0];
}

bool comp2(vector<int> &v1, vector<int> &v2){ // 합 기준 내림차
    if( v1[0] + v1[1] == v2[0] + v2[1]){
        if(v1[0] == v2[0]) return v1[1] > v2[1];
        return v1[0] > v2[0];
    }
    return v1[0] + v1[1] > v2[0] + v2[1];
}


int solution(vector<vector<int>> scores) {
    vector<int> me = scores[0];
    
    sort(scores.begin(), scores.end(), comp1);
    
    /*
    .first은 내림차, .second는 오름차.
    
    .second 값을 저장해 두고, 
    따라서 앞에서부터 순회하면서, 저장해둔 .second 값과 비교한다.
    만약 저장한 것보다 크다면 -> OK. save한다.
    저장한 것보다 작다면 -> .first는 항상 더 작고, .second는 항상 더 작다. pass한다.
    */
    
    vector<vector<int>> passes;
    int min_value = scores[0][1];
    for(int i = 0; i<scores.size(); i++){
        if(scores[i][0] > me[0] && scores[i][1] > me[1]) return -1; // 나보다 둘 다 높으면 난 못받음
         
        if(min_value > scores[i][1]){ // 오름차순 정렬한 게 min_value보다 더 작다? .first도 더 작다는 뜻.
            continue;
        }
        else{ // 아닌 경우 save
            min_value = scores[i][1];
            passes.push_back(scores[i]);
        }
    }

    sort(passes.begin(), passes.end(), comp2);
    
    for(int i = 0; i<passes.size(); i++){
        // "내"가 제일 우선순위라고 치면 된다.
        // 그러면 앞에 몇 명이 동순위든 상관없이 내 순위는 정확해지고,
        // 내가 동순위인지 상관없어진다.
        if(passes[i][0] + passes[i][1] == me[0] + me[1]) return i+1;
    }
    
    return -1;
}