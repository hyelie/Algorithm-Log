// n^2 배열 자르기

#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(ll i = left; i <= right; i++){
        answer.push_back(max(i/n, i%n) + 1);
    }
    
    return answer;
}

/*
1 2 3
2 2 3
3 3 3

(0,0) : 1

(1,0), (1,1), (0,1) : 2

(2, 0), (2, 1), (2,2), (1,2), (0,2) : 3

-> max(r, c) + 1

1 2 3 4
2 2 3 4
3 3 3 4
4 4 4 4

1 2 3 4 2 2 3 4 3 3 3 4 4 4 4 4
n
어떤 숫자가 주어진다고 하자. 이 숫자를 배열의 idx로 바꿀 수 있겠는가
0 1 2 3 4 5 6 7 8 9 ...
n/4, n%4

10^7행/열..? 이거 다 채우고 자른다는 생각이면 절대 못함. 무조건 O(n)
10000000
*/