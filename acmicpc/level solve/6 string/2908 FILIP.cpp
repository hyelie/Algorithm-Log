#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);

	string A, B;
	cin>>A;
	cin>>B;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	
	cout<< (A < B ? B : A);
	
	return 0;
}