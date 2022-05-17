// 보행자 천국

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int MOD = 20170805;

typedef pair<int, int> pii;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<pii>> dist(m, vector<pii>(n, {0, 0})); // dist[r][c].first : r방향, .second : c방향
    for(int i = 0; i<m; i++){
        if(city_map[i][0] == 1) break;
        dist[i][0].first = 1;
        dist[i][0].second = city_map[i][0] == 2 ? 0 : 1;
    }
    for(int i = 0; i<n; i++){
        if(city_map[0][i] == 1) break;
        dist[0][i].first = city_map[0][i] == 2 ? 0 : 1;
        dist[0][i].second = 1;
    }
    
    /*for(vector<pii> vi : dist){
        for(pii i : vi){
            cout<<i.first<<" "<<i.second<<"\t";
        }cout<<endl;
    }*/
    
    for(int r = 1; r<m; r++){
        for(int c = 1; c<n; c++){
            if(city_map[r][c] == 1){
                dist[r][c].first = dist[r][c].second = 0;
                continue;
            }
            else if(city_map[r][c] == 2){
                dist[r][c].first = dist[r-1][c].first % MOD;
                dist[r][c].second = dist[r][c-1].second % MOD;
            }
            else{
                dist[r][c].first = dist[r][c].second = (dist[r-1][c].first % MOD + dist[r][c-1].second % MOD) % MOD;
            }
        }
    }
    
    return dist[m-1][n-1].first;
}