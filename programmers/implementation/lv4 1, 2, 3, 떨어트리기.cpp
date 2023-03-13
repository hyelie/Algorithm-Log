#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int vsize;
vector<vector<int>> edge; // edge[i] : vertex i부터 출발하는 edge
vector<int> vertex; // vertex[i] : vertex i가 보고 있는 child index
vector<vector<int>> result; // 순회 결과로 쌓이는 결과
vector<int> Target; // target의 전역변수
int cnt = 1;

int MAKEABLE = 1, IMPOSSIBLE = 2, MAKING = 0;
int makeable(){
    for(int i = 0; i < result.size(); i++){
        if(result[i].size() > Target[i]) return IMPOSSIBLE;
        if(result[i].size() <= Target[i] && Target[i] <= 3 * result[i].size()) continue;
        else return MAKING;
    }
    return MAKEABLE;
}

int DFS(int curV){
    if(edge[curV].size() == 0){ // leaf
        result[curV-1].push_back(cnt); cnt++;
        return makeable();
    }
    
    // deeper
    int nextV = edge[curV][vertex[curV]];
    vertex[curV] = (vertex[curV] + 1) % edge[curV].size();
    return DFS(nextV);
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vsize = edges.size() + 1;
    vertex.resize(vsize + 1);
    fill(vertex.begin(), vertex.end(), 0);
    edge.resize(vsize+1);
    for(vector<int> vi : edges){
        edge[vi[0]].push_back(vi[1]);
    }
    for(vector<int>& vi : edge) sort(vi.begin(), vi.end(), less<int>());
    result.resize(target.size());
    Target = target;
    
    while(1){
        int DFSresult = DFS(1);
        if(DFSresult == IMPOSSIBLE) return {-1};
        else if(DFSresult == MAKING) continue;
        else{ // MAKEABLE
            vector<int> answer(cnt-1, 0);
            
            for(int i = 0; i<result.size(); i++){
                int object = Target[i];
                for(int ridx = 0; ridx < result[i].size(); ridx++){
                    int numleft = result[i].size() - ridx;
                    int answeridx = result[i][ridx];
                    // 앞에서부터 작은 수를 너흥ㄹ 수 있다면 그 수를 넣으면 됨
                    // 넣을 수 있는 개수
                    if(numleft == 1){ // 1개짜리면 원래 값 넣어 주어야 함
                        answer[answeridx - 1] = object;
                    }
                    else if(object - 1 <= 3*(numleft - 1)){ // 1을 넣었을 때 나머지 값으로 충당 가능
                        answer[answeridx - 1] = 1;
                        object -= 1;
                    }
                    else if(object - 2 <= 3 * (numleft - 1)){ // 2를 ~
                        answer[answeridx - 1] = 2;
                        object -= 2;
                    }
                    else{ // 3을 ~
                        answer[answeridx - 1] = 3;
                        object -= 3;
                    }
                }
            }
            return answer;
        }
    }
    
    return {-1};
}

// 다 1 넣고, 뒤에서부터 큰 수 넣으면 될 것 같은데?
// 글면 result 배열에 쌓이는 vertex 순서를 넣어야 할 듯? 