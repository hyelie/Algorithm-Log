// 숫자의 표현

#include <string>
#include <vector>

using namespace std;

int partial_sum(int start, int end){
    return (start + end) * (end - start + 1) / 2;
}

int solution(int n) {
    vector<int> dp(n+1, 0); // dp[i] : i를 표현하는 방법의 수
    for(int i = 1; i<=n; i++){
        for(int j = i; partial_sum(i, j) <= n; j++){
            dp[partial_sum(i, j)]++;
        }
    }
    return dp[n];
}

/*
시작점 : i, 종료점 : j로 봤을 때
dp[x] : x를 표현하는 방법의 수라고 하자
그러면 inner for loop에서 partial_sum은 약 200번 돈다는 것을 상한으로 둘 수 있다 그래서 O(n)
또 two-pointer로도 풀 수 있다는 것 같다 !
*/