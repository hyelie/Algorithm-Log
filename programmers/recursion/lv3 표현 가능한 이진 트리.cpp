#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> treeSizes; // full binary tree의 vertex 개수

// full binary tree vertex 개수 초기화
ll MAX_VALUE = 1000000000000000;
void init(){
    ll power = 2L, num = 1L;
    while(1){
        if(num >= MAX_VALUE) break;
        num *= power;
        treeSizes.push_back(num - 1);
    }
}

string toBinaryString(ll n){
    string result = "";
    while(n){
        result = to_string(n % 2) + result;
        n /= 2;
    }
    return result;
}

// 전체 size가 n이어야 할 때 앞자리에 0을 채워줌
string fillZeros(string str, ll n){
    while(str.length() != n){
        str = "0" + str;
    }
    return str;
}

// node 개수 n을 넣었을 때 full binary tree의 node 개수
ll getFullTreeSize(ll n){
    return *(lower_bound(treeSizes.begin(), treeSizes.end(), n));
}

// s.length()는 2^k-1으로 정해져 있음
bool isMakeable(string s, ll start, ll end){
    if(start == end) return true; // base case : size가 1이 경우 항상 makeable
    
    // *** 실수 : 0001000과 같은 경우를 생각하지 못함
    // 가운데가 0인데 나머지에 1이 있는 경우 : 못만듬. 전부 다 0이면 makeable
    // 가운데가 1인 경우 : 양 subtree를 만들 수 있어야 함
    ll mid = start + (end - start) / 2;
    if(s[mid] == '0'){
        ll left = start, right = end;
        while(left < mid){
            if(s[left] == '1' || s[right] == '1') return false;
            left++; right--;
        }
        return true;
    }
    
    bool left = isMakeable(s, start, mid-1);
    bool right = isMakeable(s, mid+1, end);
    
    if(left && right) return true; // 좌 우 모두 탐색 가능해야 full binary tree를 만들 수 있다.
    else return false;
}

vector<int> solution(vector<long long> numbers) {
    init();
    
    vector<int> answer;
    for(ll n : numbers){
        string binaryString = toBinaryString(n); // n의 2진수 string
        // n으로 full binary tree를 만든다고 생각하고 부족한 0을 채움
        binaryString = fillZeros(binaryString, getFullTreeSize(binaryString.length()));
        bool result = isMakeable(binaryString, 0, binaryString.length()-1); // *** 실수 : length()를 넣었음... -1 해야 함
        answer.push_back(result);
    }
    
    return answer;
}

/*
전체 만들어 두고 판단하는 건 안되고
각 수를 표현할 수 있는지를 봐야겠네

0. full binary tree의 vertex 개수를 저장한다. numbers 원소인 10^15 직후까지 : arr라 하자
 2^1 - 1, 2^2 - 1, 2^3 - 1, ...
 1        3        7
1. 각 수를 2진수 표현한다. : O(logn)
2. arr에서 [2진수 표현.length]의 lower bound 찾는다 : O(logn)
3. 부족한 만큼 앞에 0을 채워넣는다
4. 양쪽으로 binary search 해서 subtree를 못 만드는 경우 못 만드는거다.

5 - X
101

7 - OK
111

42 - OK
101010
0101010

63 - O
0111111

111 - O
1101111

95 - X
1011111

2^10 = 10^3
10^15 = 2^10^5
최대 50자리 정도?

3:00 솔 (디버깅 45분)
*/