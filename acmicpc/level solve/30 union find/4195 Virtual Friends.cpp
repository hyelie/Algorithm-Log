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

int Parent[200001], Rank[200001], childs[200001];

void Makeset(int v){
    Parent[v] = v;
    Rank[v] = 0;
}

int Find(int v){
    if(v == Parent[v]) return v;
    Parent[v] = Find(Parent[v]);
    return Parent[v];
}

void Union(int x, int y){
    int rx = Find(x);
    int ry = Find(y);

    if(ry == rx){
        cout<<childs[rx]<<'\n';
        return;
    }

    if(Rank[rx] > Rank[ry]){ // ry가 아래로
        Parent[ry] = rx;
        childs[rx] += childs[ry];
        cout<<childs[rx]<<'\n';
    }
    else{
        Parent[rx] = ry;// rx가 아래로
        if(Rank[rx] == Rank[ry]){
            Rank[ry]++;
        }
        childs[ry] += childs[rx];
        cout<<childs[ry]<<'\n';
    }
}

void solve(){
    int n; cin>>n;
    for(int i = 0; i<=200000; i++){
        Makeset(i);
        childs[i] = 1;
    }

	map<string, int> m;

    int cnt = 1;
    string a, b;
    
    for(int i = 0; i<n; i++){
        cin>>a>>b;
        if(m.find(a) == m.end()){
            m[a] = cnt++;
        }
        if(m.find(b) == m.end()){
            m[b] = cnt++;
        }

        Union(m[a], m[b]);
    }
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

	return 0;
}