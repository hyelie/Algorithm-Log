#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MAX = 201;      
vector<bool> visited(MAX, false);
int answer = 0;
vector<vector<int>> edges;

void DFS(int cur){
    visited[cur] = true;
    
    for(int i = 0; i<edges.size(); i++){
        if(edges[cur][i] && !visited[i]) DFS(i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    edges = computers;
    
    for(int i = 0; i<computers.size(); i++){
        if(!visited[i]){
            DFS(i);
            answer++;
        }
    }
    
    return answer;
}

int main(){

    cout<<solution(3, {{1,1,0}, {1,1,0}, {0,0,1}})<<endl;
}