#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;
int board_size = 8;

int stimeToMinute(string cur_time){
	return stoi(cur_time.substr(0, 2)) * 60 + stoi(cur_time.substr(3, 2));
}

string minuteToStime(int minute){
	int hh = minute / 60, mm = minute % 60;
	string sh = to_string(minute/60), sm = to_string(minute%60);
	if(hh < 10) sh = "0" + sh;
	if(mm < 10) sm = "0" + sm;
	
	return sh + ":" + sm;
}

int addTime(int time, int add_value){
	return (time + add_value) % 1440;
}

bool isPalindrome(string stime){
	if(stime[0] == stime[4] && stime[1] == stime[3]) return true;
	else return false;
}

void solve(){
	string cur_time; int duration;
	cin>>cur_time>>duration;

	int origin_time = stimeToMinute(cur_time);
	int t = origin_time;
	int answer = 0;
	do{
		if(isPalindrome(minuteToStime(t))) answer++;
		t = addTime(t, duration);
	} while(t != origin_time);
	cout<<answer<<'\n';
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}