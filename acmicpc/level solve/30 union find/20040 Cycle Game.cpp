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

int n, m;
int Parent[500001], Rank[500001];

int Find(int v){
    if(v == Parent[v]) return v;
    Parent[v] = Find(Parent[v]);
    return Parent[v];
}

bool Union(int x, int y){ // true then cycle
    int rx = Find(x), ry = Find(y);

    if(rx == ry){
        return true;
    }
    if(Rank[rx] < Rank[ry]){
        Parent[rx] = ry;
    }
    else{ // Rank[rx] >= Rank[ry]
        Parent[ry] = rx;
        if(Rank[rx] == Rank[ry]){
            Rank[rx]++;
        }
    }
    return false;
}

void solve(){
	cin>>n>>m;

    for(int i = 0; i<=n; i++){
        Parent[i] = i;
        Rank[i] = 0;
    }

    int answer = 0;
    int a, b;
    for(int i = 1; i<=m; i++){
        cin>>a>>b;
        bool result = Union(a, b);
        if(result == true && answer == 0){
            answer = i;
        }
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