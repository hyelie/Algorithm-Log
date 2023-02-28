#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
bool visited[101];
vector<int> card;
vector<int> points;

// cur : 연 상자 번호
// 모든 vertex의 outgoing edge가 1이이고 identity하므로
// 한 vertex로 2개의 incoming edge가 올 수 없다
void DFS(int cur, int point){
    if(visited[cur-1]){
        points.push_back(point);
        return;
    }
    visited[cur-1] = true;
    DFS(card[cur-1], point+1);
}

int solution(vector<int> cards) {
    n = cards.size();
    card = cards;
    
    for(int c : card){
        DFS(c, 0);
    }
    
    sort(points.begin(), points.end(), greater<int>());
    
    if(points[0] == n) return 0;
    return points[0] * points[1];
}