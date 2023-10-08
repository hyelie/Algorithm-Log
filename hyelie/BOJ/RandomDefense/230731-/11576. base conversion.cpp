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

void solve(){
	int A, B; cin>>A>>B;
    int m; cin>>m;
    vector<int> digits(m);
    for(int i = m-1; i>=0; i--) cin>>digits[i];

    int ten = 0, mul = 1;
    for(int digit : digits){
        ten += digit * mul;
        mul *= A;
    }
    
    vector<int> result;
    while(ten){
        result.push_back(ten % B);
        ten /= B;
    }
    for(int i = result.size()-1; i>=0; i--) cout<<result[i]<<' ';

}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}