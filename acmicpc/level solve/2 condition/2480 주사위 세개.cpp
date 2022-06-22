#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int a, b, c;
	cin>>a>>b>>c;

	int price;
	if(a == b && b == c){
		price = 10000 + 1000*b;
	}
	else if(a == b){
		price = 1000 + 100 * a;
	}
	else if(b == c){
		price = 1000 + 100 * b;
	}
	else if(c == a){
		price = 1000 + 100 * c;
	}
	else{
		price = max(a, max(b, c)) * 100;
	}

	cout<<price;
	return 0;
}