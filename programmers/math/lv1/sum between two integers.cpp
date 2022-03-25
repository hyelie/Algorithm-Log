#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

long long solution(int a, int b) {
    long long answer = ((ll)a + (ll)b) * (ll)(abs(b-a)+1) / (ll)2;
    return answer;
}

/*

(초항+막항) * 항 개수 / 2

*/