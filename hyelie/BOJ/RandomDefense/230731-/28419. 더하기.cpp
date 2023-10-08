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

ll solve(){
	int n; cin>>n;
    ll oddsum = 0, evensum = 0;
    int input;
    for(int i = 0; i<n; i++){
        cin>>input;
        if(i % 2 == 0) evensum += input;
        else oddsum += input;
    }

    if(oddsum == evensum) return 0;
    if(n == 3 && evensum > oddsum) return -1;
    return abs(evensum - oddsum);

    // 연산은 총 2가지.
    // evensum에 2 더하고 oddsum에 1 더하거나
    // evensum에 1 더하고 oddsum에 2 더하거나.
    // N == 3인 경우는 1번밖에 못함. -> evensum이 더 큰 경우 불가능.
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	cout<<solve();

	return 0;
}