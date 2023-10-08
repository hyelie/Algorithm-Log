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
typedef pair<char, char> pcc;

////////////////////// write your code below

// 모든 vertex에서 모든 vertex로의 path 여부를 알아야 하므로, floyd-warshall
// directed임.

int V = 52;

int char2int(char c){
    if(isupper(c)) return c - 'A';
    if(islower(c)) return c - 'a' + 26;
}

char int2char(int i){
    if(0 <= i && i <= 25) return i + 'A';
    else return i + 'a' - 26;
}

void solve(){
	int N; cin>>N;
    vector<vector<bool>> edges(52, vector<bool>(V, false)); // edges[i][j] : i부터 j까지 path 존재
    // 0 - 25까지는 대문자, 26 - 51까지는 소문자

    char from, to;
    string s;
    for(int i = 0; i<N; i++){
        cin>>from>>s>>to;
        edges[char2int(from)][char2int(to)] = true;
    }

    for(int k = 0; k<V; k++){ // k : 중간 path
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(!edges[i][j] && edges[i][k] && edges[k][j]) edges[i][j] = true;
            }
        }
    }

    int cnt = 0;
    vector<pcc> answers;
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(i != j && edges[i][j]){
                cnt++;
                answers.push_back({int2char(i), int2char(j)});
            }
        }
    }

    cout<<cnt<<'\n';
    for(pcc answer : answers){
        cout<<answer.first<<" => "<<answer.second<<'\n';
    }
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}