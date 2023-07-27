#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <cmath>
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

////////////////////// write your code below

set<char> availNums; // 사용 가능한 숫자 목록
vector<int> avails, stars;
int K, N;
int answer = 0;

// n이 사용 가능한지 검사하는 함수, 내부적으로 2가지를 본다.
// 1) 자리 수가 맞는지, 2) 사용 가능한 숫자만 있는지
bool isIntegerAvailable(int n, int len){
    // 1)
    string nstr = to_string(n);
    if(nstr.length() != len) return false;

    // 2)
    for(char c : nstr){
        bool isExist = false;
        for(int avail : avails){
            if(avail + '0' == c) isExist = true;
        }
        if(!isExist) return false;
    }
    return true;
}

// 순열 생성 결과가 문제 조건에 부합하는지 본다.
bool isPossible(int a, int b){
    // 검증
    if(!isIntegerAvailable(a*b, stars[stars.size()-1])) return false;

    int staridx = 2;
    while(b){
        if(!isIntegerAvailable(a * (b%10), stars[staridx])) return false;
        b /= 10;
        staridx++;
    }

    return true;
}

// 중복순열 생성 : A는 위, B는 아래 것.
void dupPermutationB(int depth, int a, int b){
    if(depth == stars[1]){
        if(isPossible(a, b)){
            answer++;
        }
        return;
    }

    for(int i = 0; i<avails.size(); i++){
        dupPermutationB(depth+1, a, 10*b + avails[i]);  
    }
}

void dupPermutationA(int depth, int a){
    if(depth == stars[0]){
        dupPermutationB(0, a, 0);
        return;
    }

    for(int i = 0; i<avails.size(); i++){
        dupPermutationA(depth+1, 10*a + avails[i]);
    }
}

//////////////////////

int main(void) {
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    // input
    cin >> N;
    stars.resize(N);
    for (int i = 0; i < N; i++)
        cin >> stars[i];

    cin >> K;
    avails.resize(K);
    for (int i = 0; i < K; i++)
    {
        cin >> avails[i];
    }

    // solve
    /*
    s1 = 5, s2 = 3인 경우, 총 8개
    9^8 = 4천만, 경우의 수는 충분함.
    100000 * 1000 = 100000000, 곱 연산 결과는 1억보다 작으므로 int를 써도 됨.

    1) s1+s2 PI k로 중복순열 뽑음.
    2) s1과 s2의 각 자리를 연산한다.
        - 자리수가 맞는지
        - 사용 가능한 숫자만 있는지
    3) s1 * s2의 결과값을 본다.
        - 자리수가 맞는지
        - 사용 가능한 숫자만 있는지
    */

    dupPermutationA(0, 0);

    cout << answer;

    return 0;
}