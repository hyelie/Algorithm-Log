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
	string doc, s;
    getline(cin, doc);
    getline(cin, s);

    int answer = 0, idx = 0;
    while(1){
        int nth_idx = doc.find(s, idx);
        if(nth_idx == string::npos) break;

        answer++;
        idx = nth_idx+s.length();
    }
    cout<<answer;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}