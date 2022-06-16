/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
long long INF = 1000000001;
typedef pair<int, int> pii;

int main()
{
    cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
    cin>>N>>M;
    vector<vector<pii>> edges(N+1);
    
    int from, to, weight;
    for(int i = 0; i<M; i++){
        cin>>from>>to>>weight;
        edges[from].push_back({to, weight});
    }
    
    vector<long long> dist(N+1, INF);
    dist[1] = 0;
    
    // V-1번 순회
    for(int i = 0; i< N-1; i++){
        // 모든 vertex에 대해
        for(int v = 1; v<=N; v++){
            // v의 모든 edge에 대해
            for(pii edge : edges[v]){
                int from = v, to = edge.first, weight = edge.second;
                if(dist[from] != INF) dist[to] = min(dist[to], dist[from] + edge.second);
            }
        }
    }
    
    bool hasNegCycle = false;
    for(int v = 1; v<=N; v++){
        for(pii edge : edges[v]){
            int from = v, to = edge.first, weight =edge.second;
            if(dist[from] != INF && dist[to] > dist[from] + weight){
                hasNegCycle = true;
                break;
            }
        }
    }
    
    if(hasNegCycle) cout<<"-1\n";
    else{
        for(int v= 2; v<=N; v++){
            long long value = dist[v] == INF? -1 : dist[v];
            cout<<value<<'\n';
        }
    }
    
    
    

    return 0;
}
