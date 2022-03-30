// 땅따먹기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land){
    int size = land.size(), idx = 4;

    for(int i = 1; i<size; i++){
        for(int j = 0; j<idx; j++){
            // 자동화 안되나,,,
            vector<int> temp;
            for(int k = 0; k<idx; k++){
                if(k == j) continue;
                temp.push_back(land[i-1][k]);
            }
            land[i][j] += *max_element(temp.begin(), temp.end());
        }
    }
    
    return *max_element(land[size-1].begin(), land[size-1].end());
}

// 최고점
// "그" DP

//land[i]를 보고 있을 때, land[i+1]에서 최댓값을 뽑기 위해서는 land[i]에서 고른 index를 제외한 값들 중 최댓값을 골라야 한다. 그러므로 점화식은

//land[i][0] = max(land[i][1], max(land[i][2], land[i][3]))

//이 된다. 마찬가지로 land[i][1], ... , land[i][3]도 동일하다. 이렇게 점화식을 세우고 dp 돌리면 된다.






/*
int solution(vector<vector<int> > land)
{
    int answer = 0;

    // n번째 칸을 first, second, third, fourth 칸을 밟앗을 때 점수
    long long first = land[0][0], second = land[0][1], third = land[0][2], fourth = land[0][3];
    long long prevfirst = first, prevsecond = second, prevthird = third, prevfourth = fourth;
    
    int numLandRow = land.size();
    for(int i = 1; i<numLandRow; i++){
        prevfirst = first; prevsecond = second; prevthird = third; prevfourth=fourth;
        first = max(prevsecond, max(prevthird, prevfourth)) + land[i][0];
        second = max(prevfirst, max(prevthird, prevfourth)) + land[i][1];
        third = max(prevsecond, max(prevfirst, prevfourth)) + land[i][2];
        fourth = max(prevsecond, max(prevthird, prevfirst)) + land[i][3];
    }
    
    

    return max(first, max(second, max(third, fourth)));
}*/