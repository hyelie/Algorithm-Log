// 최고의 집합

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(s/n == 0) return {-1};
    
    vector<int> answer(n, s/n);
    int r = s%n;
    for(int i = n-1; i>=0; i--){
        if(r == 0) break;
        r--; answer[i]++;
    }
    return answer;
}

// 1억
// x + y + ... + a = s
// 미지수 개수는 n개, 모두 자연수여야 함.
// x' + y' + ... + a' = s-n
// nHr : n개의 공을 r개의 상자에 중복 있이, 순서 없이 넣는 방법의 수 -> 중복조합?
// 근데 x' <= y' <= ... <= a'
// s-n개를 n개에 배분하는 경우의 수 - > (s-n)Hn
// 그러나 이 문제... 1억H1만의 경우를 모두 계산할 수 있을까?
// NO! 수학적 접근이 필요하다...