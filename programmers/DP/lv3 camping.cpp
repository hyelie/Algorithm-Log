// 캠핑

#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;


typedef pair<int, int> pii;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {    
    // 좌표 압축
    set<int, less<int>> rset, cset;
    for(int i = 0; i<n; i++){
        rset.insert(data[i][0]);
        cset.insert(data[i][1]);
    }
    
    // row 좌표 압축 후 mapping
    vector<int> compressed_r(rset.begin(), rset.end());
    map<int, int> rmapper;
    for(int i = 0; i<compressed_r.size(); i++){
        rmapper[compressed_r[i]] = i;
    }
    
    // col 좌표 압축 후 mapping
    vector<int> compressed_c(cset.begin(), cset.end());
    map<int, int> cmapper;
    for(int i = 0; i<compressed_c.size(); i++){
        cmapper[compressed_c[i]] = i;
    }
    
    // mapping된 좌표로 변경
    for(vector<int> &vi : data){
        vi[0] = rmapper[vi[0]];
        vi[1] = cmapper[vi[1]];
    }
    // 좌표 압축 완료
    
    // psum[i][j] : {0, 0} ~ {i, j}까지 쐐기의 개수 ({i, j}는 미포함)
    // 누적합으로 구할 수 있음
    int maxnum = 5001;
    vector<vector<int>> psum(maxnum, vector<int>(maxnum, 0));
    
    for(vector<int> &vi : data){
        psum[vi[0]][vi[1]] = 1;
    }
    
    // 누적합 기본 설정
    for(int i = 1; i<maxnum; i++){
        psum[i][0] = psum[i-1][0];
        psum[0][i] += psum[0][i-1];
    }
    for(int r = 1; r<maxnum; r++){
        for(int c = 1; c<maxnum; c++){
            psum[r][c] += psum[r-1][c] + psum[r][c-1] - psum[r-1][c-1];
        }
    }
    
    // 구하기
    int answer = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int rmin = min(data[i][0], data[j][0]);
            int rmax = max(data[i][0], data[j][0]);
            int cmin = min(data[i][1], data[j][1]);
            int cmax = max(data[i][1], data[j][1]);
            
            if(rmin == rmax || cmin == cmax) continue;
            
            int num_wedge = psum[rmax - 1][cmax - 1] - psum[rmax - 1][cmin] - psum[rmin][cmax - 1] + psum[rmin][cmin];
            if(num_wedge == 0) answer++;
        }
    }
    
    return answer;
}

/*
어떤 점 2개를 골랐을 때 그 사이에 있는 점만 고르는 방법이 없을까?
이게 핵심
인풋이 5천이니 n^2으로 풀어라는 말인데...
data의 조합을 구하는 것 만으로도 이미 n^2임
그러면 1개의 조합을 구했을 때, 설치 가불(안에 뭔가 있는지)를 O(logn)으로 구할 수 있는가?
좌표 압축으로 쉽게 구할 수 있다네요~ 
*/