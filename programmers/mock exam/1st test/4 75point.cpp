#include <string>
#include <vector>
#include <iostream>
using namespace std;

int n;

vector<int> rev(vector<int> v){
	for(int &i : v){
		i = 1 - i;
	}
	return v;
}

bool cmp(vector<int> &a, vector<int>& b){
	for(int i = 0; i<a.size(); i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}

int NINF = -99999;

int solve(vector<vector<int>> diff, vector<int>&standard, vector<int>& rev_standard){
	int answer = 0;
	for(int r = 1;r<n; r++){
		if(cmp(standard, diff[r])) continue;
		else if(cmp(rev_standard, diff[r])){
			diff[r] = rev(diff[r]);
			answer++;
		}
		else return NINF;
	}
    for(int i : standard) if(i == 1) answer++;
	return answer;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
	n = beginning.size();
	vector<vector<int>> diff(n, vector<int>(n, 0));
	for(int r= 0; r<n; r++){
		for(int c= 0 ; c<n; c++){
			if(beginning[r][c] != target[r][c]){
				diff[r][c] = 1;
			}
		}
	}

	vector<int> standard(diff[0].begin(), diff[0].end());
	vector<int> rev_standard = rev(standard);
   	int a = solve(diff, standard, rev_standard);
	int b = solve(diff, rev_standard, standard) + 1;
	//cout<<a<<' '<<b<<endl;

	if(a < -1 && b < -1) return -1;
	else if(a < -1 && b >= 0) return b;
	else if(a >= 0 && b < -1) return a;
	else return min(a, b);
      

    //return min(a, b);
}