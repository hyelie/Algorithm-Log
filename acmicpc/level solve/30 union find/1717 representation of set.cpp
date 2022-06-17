/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int Parent[1000001];
int Rank[1000001];

void Makeset(int s){
    Parent[s] = s;
    Rank[s] = 0;
    return;
}

int Find(int x){
    if(x == Parent[x]) return x;
    
    Parent[x] = Find(Parent[x]); // x의 parent를 x의 root로 설정
    return Parent[x];
}

void Union(int x, int y){
    int rx = Find(x);
    int ry = Find(y);
    if(rx == ry) return;
    
    if(Rank[rx] < Rank[ry]) // ry의 height가 더 크면 rx가 밑으로 글어가야 함
        Parent[rx] = ry;
    else{ // 그렇지 않다면 ry가 밑으로 들어가야 함
        Parent[ry] = rx;
        if(Rank[rx] == Rank[ry]){ // rank가 같으면 rank 조절
            Rank[ry]++;
        }
    }
}

int main()
{
    cin.tie(0);
	std::ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<=n; i++){
        Makeset(i);
    }
    
    while(m--){
        int op, a, b;
        cin>>op>>a>>b;
        if(op == 0){
            Union(a, b);
        }else{
            int ra = Find(a), rb = Find(b);
            if(ra == rb) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

    return 0;
}
