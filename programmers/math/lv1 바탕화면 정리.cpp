#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
    // 시작x, 시작y, 도착x, 도착y
    
    for(int r = 0; r<wallpaper.size(); r++){
        for(int c = 0; c<wallpaper[r].size(); c++){
            if(wallpaper[r][c] == '#'){
                answer[0] = min(answer[0], r);
                answer[1] = min(answer[1], c);
                answer[2] = max(answer[2], r+1);
                answer[3] = max(answer[3], c+1);    
            }
            
        }
    }
    return answer;
}

// 직사각형 위치 찾으면 됨