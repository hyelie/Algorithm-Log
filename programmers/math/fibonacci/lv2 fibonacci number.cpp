// 피보나치 수

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int MOD = 1234567;
    int z = 0, f = 1, temp;
    for(int i = 2; i<=n; i++){
        temp = f;
        f = ( z % MOD + f % MOD ) % MOD;
        z = temp;
    }
    return f;
    
}













/*
int MOD = 1234567;

int solution(int n) {
    int first = 0, second = 1, temp;
    for(int i = 1; i<n; i++){
        temp = ((first % MOD)+ (second % MOD)) % MOD;
        first = second;
        second = temp;
    }
    return second;
}*/
/*

0 1 1 2 3 5
0 1 2 3 4 5

*/