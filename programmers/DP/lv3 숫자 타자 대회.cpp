#include <string>
#include <vector>
#include <iostream>

using namespace std;

// weights[i][j] : 숫자 i부터 j까지 가중치
vector<vector<int>> weights = {
    {1, 7, 6, 7, 5, 4, 5, 3, 2, 3}, // 0
    {7, 1, 2, 4, 2, 3, 5, 4, 5, 6}, // 1
    {6, 2, 1, 2, 3, 2, 3, 5, 4, 5}, // 2
    {7, 4, 2, 1, 5, 3, 2, 6, 5, 4}, // 3
    {5, 2, 3, 5, 1, 2, 4, 2, 3, 5}, // 4
    {4, 3, 2, 3, 2, 1, 2, 3, 2, 3}, // 5
    {5, 5, 3, 2, 4, 2, 1, 5, 3, 2}, // 6
    {3, 4, 5, 6, 2, 3, 5, 1, 2, 4}, // 7
    {2, 5, 4, 5, 3, 2, 3, 2, 1, 2}, // 8
    {3, 6, 5, 4, 5, 3, 2, 4, 2, 1}  // 9
};

int dp[100001][11][11]; // dp[i][j][k] : i번째 숫자를 왼손은 j, 오른손은 k로 눌렀을 때 최소값
int INF = 987654321;
int len;
vector<int> Numbers;

void init(){
    for(int i = 0; i<=100000; i++){
        for(int j = 0; j<=10; j++){
            for(int k = 0; k<=10; k++){
                dp[i][j][k] = INF;
            }
        }
    }
}

int recurse(int i, int j, int k){
    if(dp[i][j][k] != INF) return dp[i][j][k];
    if(i == len) return 0;
    
    // 왼손이 움직이는 경우 : 오른손 위치와 달라야함
    if(Numbers[i] != k){
        dp[i][j][k] = min(dp[i][j][k], recurse(i+1, Numbers[i], k) + weights[j][Numbers[i]]);
    }
    
    // 오른손이 움직이는 경우 : 왼손 위치와 달라야 함
    if(Numbers[i] != j){
        dp[i][j][k] = min(dp[i][j][k], recurse(i+1, j, Numbers[i]) + weights[k][Numbers[i]]);    
    }
    
    return dp[i][j][k];
}

int solution(string numbers) {
    len = numbers.size();
    init();
    Numbers.resize(len);
    for(int i = 0; i<len; i++){
        Numbers[i] = numbers[i] - '0';   
    }
    
    
    return recurse(0, 4, 6);
}

/*
왼손을 움직이는 경우, 오른손을 움직이는 경우
모든 case에서 이 두가지 경우의 수가 있다.
DP를 써야 할 것 같은데
dp[i][j] : 숫자 i를 손 j로 입력했을 때 최솟값
이렇게 두면?
그러면 i를 입력한 손의 위치는 j에 있을 것

dp[i][0] = min(dp[i-1][0] + weights[prev0][i], dp[i-1][1] + weights[prev1][i])
숫자 i를 0으로 입력했을 때 : 
 - i-1을 0으로 입력하고 i를 0으로 입력할 때
 - i-1을 1로 입력하고 i를 0으로 입력할 때
 - 이하 2개의 case
 - 같은 위치에 있으면 안되니까 i-1 == i일 때는 dp[i][0] = dp[i-1][0] + 1
 - 맞나?
 
 
dp[i][j] (왼손, 오른손)
"1756"
  0        1
0 2(1, 6)  5(4, 1)
1 6(7, 6)  7(1, 7)
2 9(5, 6)  8(7, 5)
3 11(7, 6) 10(7, 6)

(4, 6) "5123"
  0        1
0 2(5, 6)  2(4, 5)
1 4(1, 5)  5(4, 1)
2 6(2, 5)  6(1, 2)  
3 8(3, 5)  8(1, 3)


10252525252525
 9 (1, 0)
 11 (2, 0)
 15 ()

*/