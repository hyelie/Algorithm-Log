/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int V, E;
typedef pair<int, int> pii;
int INF = 2000001;

struct mycomp{
    bool operator()(pii&a, pii&b){
        return a.second > b.second; // weight가 큰 것을 앞으로
    }
};

vector<int> dijkstra(int start, vector<vector<pii>> edges){
    vector<int> dist(V+1, INF);
    dist[start] = 0;
    
    priority_queue<pii, vector<pii>, mycomp> pq;
    pq.push({start, 0});
    
    while(!pq.empty()){
        int u = pq.top().first;
        int u_weight = pq.top().second;
        pq.pop();
        
        for(pii &edge : edges[u]){
            int v = edge.first, v_weight = edge.second;
            if(dist[v] > dist[u] + v_weight){
                dist[v] = dist[u] + v_weight;
                pq.push({v, dist[v]});
            }
        }
    }
    return dist;
}

int main()
{
    cin.tie(0);
	std::ios_base::sync_with_stdio(0);
    cin>>V>>E;
    vector<vector<pii>> edges(V+1); // edges[i] : edge start가 i인 edge list. edges[i].first : edge end, .edge[i].second : 해당 edge의 weight
    int s; cin>>s;
    
    int from, to, weight;
    for(int i= 0; i<E; i++){
        cin>>from>>to>>weight;
        edges[from].push_back({to, weight});
    }
    
    vector<int> dist = dijkstra(s,edges);
    
    for(int i = 1; i<=V; i++){
        if(dist[i] == INF) cout<<"INF\n";
        else cout<<dist[i]<<'\n';
    }
    

    return 0;
}
