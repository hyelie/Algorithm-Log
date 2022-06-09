// 기둥과 보 설치

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int totalsize;

bool isOK(vector<vector<pii>>& frames, int x, int y){
    bool pillar = frames[x][y].first == 1 ? false : true;
    if(frames[x][y].first == 1){ // 기둥
        bool first = y == 0; // 바닥 위거나
        bool second = x-1 >= 0 && frames[x-1][y].second == 1; // 보의 한쪽 끝 부분 위거나
        bool third = frames[x][y].second == 1;
        bool fourth = y-1 >= 0 && frames[x][y-1].first == 1; // 다른 기둥 위에 있어야 함
        if(first || second || third || fourth){
            pillar = true;
        }
    }
    
    bool beam = frames[x][y].second == 1 ? false : true;
    if(frames[x][y].second == 1){ // 보
        bool first = y-1>=0 && frames[x][y-1].first == 1; // 한쪽 끝 부분이 기둥 위에 있거나
        bool second = x+1 <= totalsize && y-1 >= 0 && frames[x+1][y-1].first == 1; // 반대쪽 끝 부분이 기둥 위에 있거나
        bool third = x+1 <= totalsize && frames[x+1][y].second == 1 && x-1>=0 && frames[x-1][y].second == 1; // 양쪽 끝 부분이 다른 보와 동시에 연결되어야 함
        if(first || second || third){
            beam = true;
        }
    }
    if(beam && pillar) return true;
    else return false;
}

bool isBuildingOK(vector<vector<pii>>& frames){
    for(int x = 0; x<=totalsize; x++){
        for(int y = 0; y<totalsize; y++){
            if(!isOK(frames, x, y)) return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    totalsize = n;
    vector<vector<pii>> frames(n+1, vector<pii>(n+1, {0, 0})); //.first : 기둥,, .second : 보
    
    for(vector<int> vi : build_frame){
        int x = vi[0], y = vi[1], a = vi[2], b = vi[3];
        if(b == 0){ // 삭제
            if(a == 0){ // 기둥
                frames[x][y].first = 0;
                if(!isBuildingOK(frames)){
                    frames[x][y].first = 1;
                }
            } else{ // 보
                frames[x][y].second = 0;
                if(!isBuildingOK(frames)){
                    frames[x][y].second = 1;
                }
            }
        } else{// 추가
           if(a == 0){ // 기둥
                frames[x][y].first = 1;
                if(!isBuildingOK(frames)){
                    frames[x][y].first = 0;
                }
            } else{ // 보
                frames[x][y].second = 1;
                if(!isBuildingOK(frames)){
                    frames[x][y].second = 0;
                }
            } 
        }
    }
    
    vector<vector<int>> answer;
    
    for(int x = 0; x<=n; x++){
        for(int y = 0; y<=n; y++){
            if(frames[x][y].first == 1){
                answer.push_back({x, y, 0});
            }
            if(frames[x][y].second == 1){
                answer.push_back({x, y, 1});
            }
        }
    }
    
    return answer;
}

// 설치 / 삭제 | 기둥(0) / 보(1)
/*
기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.

기둥 설치 (x, y에 설치)
y == 0이거나 / x-1, y에 보가 있거나 / x, y에 보가 있거나 / x, y-1에 기둥이 있거나 - 가 아니라면 잘못된 것
기둥 삭제
y+1에 있는 보가 모두 조건을 만족하는지

보 설치 (x, y에 설치)
x, y-1에 기둥이 있거나 / x+1, y-1에 기둥이 있거나 / x+1, y에 보가 있고 + x-1,y에 보가 있거나 - 가 아니라면 잘못된 것
보 삭제
y에 있는 보가 모두 조건을 만족하는지


기둥 삭제

*/