#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> _B) {
    //sort(A.begin(), A.end(), less<int>());
    multiset<int> B;
    for(int b : _B) B.insert(b);
    
    int answer = 0;
    for(int a : A){
        auto b_iter = B.upper_bound(a);
        if(b_iter == B.end()){ // 없으면 제일 작은 애 출전
            B.erase(B.begin());
        }
        else{ // 있으면 그친구
            B.erase(b_iter);
            answer++;
        }
    }
    return answer;
}

/*
A팀의 낮은 점수부터, B팀에서 ub를 찾으면 되는 듯.
*/