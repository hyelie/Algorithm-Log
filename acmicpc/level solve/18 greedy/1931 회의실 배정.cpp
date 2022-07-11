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
	vector<pii> meetings(N);
	for(int i = 0; i<N; i++) cin>>meetings[i].first>>meetings[i].second;
	sort(meetings.begin(), meetings.end(), cmp);

	int answer = 1, cur_endtime = meetings[0].second;
	for(int i = 1; i<N; i++){
		if(meetings[i].first < cur_endtime) continue;
		else{
			cur_endtime = meetings[i].second;
			answer++;
		}
	}
	cout<<answer;
	

	//////////////////////

	return 0;
}