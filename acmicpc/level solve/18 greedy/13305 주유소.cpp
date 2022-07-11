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
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

// .first : start time, .second : end time
bool cmp(pii&a, pii&b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	vector<int> dist(N-1), price(N);
	for(int i = 0; i<N-1; i++) cin>>dist[i];
	for(int i = 0; i<N; i++) cin>>price[i];

	ll total_cost = 0;
	for(int i = 0; i<N;){
		ll dist_sum = dist[i], cur_price = price[i]; // 현재 점-다음 점의 거리, 현재 가격
		while(i + 1 < N && cur_price <= price[i+1]){ // 다음 도시의 가격이 더 비싸다면 더 전진
			i++;
			dist_sum += dist[i];
		} // 도착지는 더 싼 지점
		total_cost += cur_price * dist_sum;
		i++;
	}

	cout<<total_cost;

	/*

	현재 점 기준, 기름 가격이 더 싸질 때까지 그 도시로 가면 됨
	해당 도시까지 이동하면, 같은 것을 반복.

	*/



	//////////////////////

	return 0;
}