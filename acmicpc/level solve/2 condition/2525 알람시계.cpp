#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
ㅎ
int time_to_min(int h, int m){
	return (60 * h + m) % 1440;
}

pii min_to_hm(int m){
	int h = m / 60;
	m %= 60;
	return {h, m};
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int a, b, c;
	cin>>a>>b>>c;

	int m = time_to_min(a, b + c);
	pii result = min_to_hm(m);
	cout<<result.first<<" "<<result.second;


	return 0;
}