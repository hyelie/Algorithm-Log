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
typedef pair<int, double> pid;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;

////////////////////// write your code below

ll Parent[100001], Rank[100001];
ll answer = 0;

ll Find(ll v){
    if(v == Parent[v]) return v;
    Parent[v] = Find(Parent[v]);
    return Parent[v];
}

void Union(ll x, ll y){
    ll rx = Find(x), ry = Find(y);
    if(rx == ry) return;
    if(Rank[rx] < Rank[ry]){
        Parent[rx] = ry;
    }
    else{
        Parent[ry] = rx;
        if(Rank[rx] == Rank[ry]){
            Rank[rx]++;
        }
    }
}

struct diff{
    ll dist, u, v;
};

bool cmp(diff&a, diff&b){
    return a.dist < b.dist;
}

void solve(){
	ll N; cin>>N;

    /*
        x좌표, y좌표, z좌표로 정렬 한 후 인접한 값의 차이로만 edge를 구성한다.
        point가 a b c 순서일 때 kruskal의 정의 상 smallest edge부터 사용하기 때문에
        b - a, c - b를 사용한다.
        a -> c는 a -> b -> c로 표현되기 때문에 a -> c의 edge를 고려할 필요가 없다.
    */

    // push each axis coordinate
    vector<pll> Xs(N), Ys(N), Zs(N); // .first : K value of index i, .second : index
    for(int i = 0; i<N; i++){
        cin>>Xs[i].first>>Ys[i].first>>Zs[i].first;
        Xs[i].second = i;
        Ys[i].second = i;
        Zs[i].second = i;
    }
    sort(Xs.begin(), Xs.end(), less<pll>());
    sort(Ys.begin(), Ys.end(), less<pll>());
    sort(Zs.begin(), Zs.end(), less<pll>());

    // push minimum difference of each axis coordinate
    vector<diff> diffs;
    diff temp;
    for(int i = 0; i<N-1; i++){
        temp.dist = Xs[i+1].first - Xs[i].first;
        temp.u = Xs[i+1].second; temp.v = Xs[i].second;
        diffs.push_back(temp);

        temp.dist = Ys[i+1].first - Ys[i].first;
        temp.u = Ys[i+1].second; temp.v = Ys[i].second;
        diffs.push_back(temp);

        temp.dist = Zs[i+1].first - Zs[i].first;
        temp.u = Zs[i+1].second; temp.v = Zs[i].second;
        diffs.push_back(temp);
    }
    sort(diffs.begin(), diffs.end(), cmp);

    for(int i = 0; i<=N; i++){
        Parent[i] = i;
        Rank[i] = 0;
    }

    for(diff elem : diffs){
        if(Find(elem.u) != Find(elem.v)){
            Union(elem.u, elem.v);
            answer += elem.dist;
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