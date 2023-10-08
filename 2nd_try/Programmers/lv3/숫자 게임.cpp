// 놓친 점 : multiset 써야 한다. set 쓰면 중복 처리 못해서 erase에서 오류남.
// 이상한 점. set erase는 O(logn)일 텐데. n = 10만에서 O(nlogn)이 안된다.
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;
/*
int solution(vector<int> A, vector<int> B) {
    multiset<int> s(B.begin(), B.end());
    int answer = 0;
    set<int>::iterator iter;
    for(int point : A){
        
        iter = upper_bound(s.begin(), s.end(), point);
        if(iter == s.end()){ // point보다 큰 것이 없는 경우
            s.erase(s.begin());
        }
        else{ // 존재 : point보다 큰 것중 제일 작은 것
            s.erase(iter);
            answer++;
        }
    }
    
    return answer;
}*/

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), less<int>()); // 오름차
    int start = 0, end = B.size()-1;
    int answer = 0;
    for(int point : A){
        if(point >= B[end]){ // B가 못이기는 경우
            start++;
        }
        else{
            end--;
            answer++;
        }
    }
    
    return answer;
}

/*
전략 1. 제일 차이가 적은, 이길 수 있는 애로 이기기
-> upper bound. k 값 초과가 처음 나타나는 위치
*/