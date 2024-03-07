#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

ll dq(int d, ll k){ // depth d일 때, k번째 수 앞에 있는 수 개수
    if(d == 1){
        if(k >= 3) k--;
        return k;
    }
    
    ll div = pow(5, d-1);
    
    ll q = k/div;
    ll r = k-q*div;
    
    ll answer = 0;
    for(int i = 0; i<q; i++){
        if(i == 2) continue;
        answer += dq(d-1, div);
    }
    if(r != 0) answer += dq(d-1, r);
    
    return answer;
}

int solution(int n, long long l, long long r) {
    
    cout<<dq(3, 120)<<endl;
    
    return 0;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	vector<string> t = {"SL","LR"};

	solution(2, 3, 17);
	
	return 0;
}