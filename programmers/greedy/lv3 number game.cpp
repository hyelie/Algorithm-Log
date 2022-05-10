// 숫자 게임

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int ai, bi;
    for(ai = 0, bi = 0; ai < A.size() && bi < B.size();){
        if(A[ai] >= B[bi]){
            bi++;
        } else{
            ai++; bi++;
        }
    }
    
    return ai;
}

// A, B 둘다 오름차순 정렬된 상태에서 A가 이기는 경우 -> B가 이길 때까지 해당 index를 뒤로 보냄(no count, 그리고 이 경우는 어차피 짐). 해당 B[i]의 경우에는 A[i]와 비교하든 더 큰 수와 비교하든 어차피 지기 때문에 A[i]와 B[i+1]을 비교함. B 입장에선 A[i]보다 무조건 큰 A[i+1]과 B[i+1]을 대는 것보다는 A[i]와 B[i+1]을 대는 것이 더 이길 확률이 높기 때문. 이 것을 B가 이길 때까지 반복함.