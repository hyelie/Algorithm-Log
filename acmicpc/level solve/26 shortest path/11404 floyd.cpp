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

int n, m;
int INF = 10000001;

int main()
{
    cin>>n>>m;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    for(int i = 1;i <=n; i++){
        dist[i][i] = 0;
    }
    int from, to, weight;
    for(int i =0; i<m; i++){
        cin>>from>>to>>weight;
        dist[from][to] = min(dist[from][to], weight);
    }
    
    for(int temp = 1; temp <= n; temp++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                dist[from][to] = min(dist[from][temp] + dist[temp][to], dist[from][to]);
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1;j <=n; j++){
            int value = dist[i][j] == INF ? 0 : dist[i][j];
            cout<<value<<' ';
        }cout<<'\n';
    }
    

    return 0;
}
