#include <string>
#include <vector>

using namespace std;

/*

vector<int> dp(10001, 0); // dp[i] : 연속된 자연수로 i를 표현하는 방법의 개수
int INF = 10001;

int solution(int n) {
    for(int i = 1; i<=n; i++){
        for(int len = 1;)
        for(int j = i; j<=5000; j++){
            int sum = (j - i + 1) * (i + j) / 2;
            if(sum >= INF) continue;
            dp[sum]++;
        }
    }
    
    return dp[n];
}*/

int getSum(int s, int e){
    return (e - s + 1) * (s + e) / 2;
}

int solution(int n) {
    // dp 실패했으니 sliding window로 해 볼까? two pointer로.
    int s = 1, e = 1, answer = 0;
    while(s <= n){
        if(s > e){
            e = s;
            continue;
        }
        
        int sum = getSum(s, e);
        if(sum == n){
            answer++;
            s++;
            continue;
        }
        if(sum < n) e++;
        else if(sum > n) s++;
    }
    return answer;
}

