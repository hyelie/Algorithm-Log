// 여행경로

#include <string>
#include <vector>

using namespace std;

vector<string> answer;

bool cmp(vector<string> &a, vector<string>&b){
    for(int i = 0; i<a.size(); i++){
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
        else continue;
    }
}

void DFS(int depth, int max_depth, string dep, vector<bool>& visited, vector<vector<string>>& tickets, vector<string>& result){
    if(depth == max_depth){
        if(answer.empty()) answer = result;
        answer = cmp(answer, result)? answer : result;
        return;
    }
    
    for(int i = 0; i<max_depth; i++){
        if(tickets[i][0] == dep && !visited[i]){
            visited[i] = true;
            result[depth + 1] = tickets[i][1];  
            DFS(depth+1, max_depth, tickets[i][1], visited, tickets, result);
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int size = tickets.size();
    vector<string> result(size + 1); result[0] = "ICN";
    vector<bool> visited(size, false);
    DFS(0, tickets.size(), "ICN", visited, tickets, result);
    return answer;
}