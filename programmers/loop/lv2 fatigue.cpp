// 피로도

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    
    do{
        int fatigue = k, cnt = 0;
        for(vector<int> dungeon : dungeons){
            if(dungeon[0] > fatigue){
                continue;
            }
            fatigue -= dungeon[1];
            cnt++;
        }
        answer = max(cnt, answer);
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}