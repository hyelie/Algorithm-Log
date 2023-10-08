#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    // 만들 수 없는 경우 : 
    if(n > s) return {-1};
    
    // 중앙값일 때 곱이 최대
    int q = s/n;
    vector<int> answer(n, q);
    int diff = s % n;
    // answer 배열의 뒤에서부터 diff개에 1씩 더해주면 됨
    for(int i = n-1, cnt = 1; cnt <= diff; i--, cnt++){
        answer[i]++;
    }
    
    return answer;
}