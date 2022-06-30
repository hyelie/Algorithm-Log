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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	vector<double> v;
	vector<double> integers = {10, 30, 50, 70, 90, 110, 130, 150, 170, 190};
	vector<double> points = {1, 3, 5, 7, 9};

	for(int i = 0; i<integers.size(); i++){
		v.push_back(integers[i]);
		for(int j = 0; j<points.size(); j++){
			v.push_back(integers[i] + points[j]);
		}
	}
	for(int j = 0; j<points.size(); j++) v.push_back(points[j]);

	set<vector<double>> answer;

	for(int i = 0; i<v.size(); i++){
		for(int j = 0; j<v.size(); j++){
			for(int k = 0; k<v.size(); k++){
				if(v[i] + v[j] + v[k] == 300){
					vector<double> temp = {v[i], v[j], v[k]};
					sort(temp.begin(), temp.end());

					answer.insert(temp);
				}
			}
		}
	}

	/*cout<<fixed;
	cout.precision(1);*/
	for(vector<double> vi : answer){

		cout<<vi[0]/10<<' '<<vi[1]/10<<' '<<vi[2]/10<<'\n';
	}
	cout<<answer.size();
	



	//////////////////////

	return 0;
}