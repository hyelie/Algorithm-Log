// 교점에 별 만들기

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;


vector<string> solution(vector<vector<int>> line) {
    vector<pii> itst;
    int size = line.size();
    ll A, B, C, D, E, F;
    double x, y;
    for(int i = 0; i<size; i++){
        for(int j = i+1; j<size; j++){
            A = line[i][0]; B = line[i][1]; E = line[i][2];
            C = line[j][0]; D = line[j][1]; F = line[j][2];
            x = (double)(B*F - E*D) / (double)(A*D - B*C);
            y = (double)(E*C - A*F) / (double)(A*D - B*C);
            if(x == (ll)x && y == (ll)y){
                itst.push_back({x, y});
            }
        }
    }
    
    sort(itst.begin(), itst.end());
    itst.erase(unique(itst.begin(), itst.end()), itst.end());
    vector<ll> xv(itst.size()), yv(itst.size());
    
    for(int i = 0; i<itst.size(); i++){
        xv[i] = itst[i].first;
        yv[i] = itst[i].second;
    }
    
    ll minx = *min_element(xv.begin(), xv.end());
    ll maxx = *max_element(xv.begin(), xv.end());
    ll miny = *min_element(yv.begin(), yv.end());
    ll maxy = *max_element(yv.begin(), yv.end());
    int row = maxx - minx + 1, col = maxy - miny + 1;
    

    
    string base = "";
    for(int i = 0; i<row; i++){
        base += ".";
    }
    vector<string> answer;
    for(int i = 0; i<col; i++){
        answer.push_back(base.substr(0));
    }
    
    for(int i = 0; i<itst.size(); i++) {
        answer[col - 1 - yv[i] -miny][xv[i]-minx] = '*';
    }

    
    return answer;
}

/*

Ax + By + E = 0
BC/Dx + By + BF/D = 0
A - BC/Dx + E - BF/D = 0
AD/D - BC/Dx = BF/D - ED/D
(AD-BC)x = (BF-ED)
x = (BF - ED) / (AD - BC)
같이, y = (EC - AF) / (AD - BC)

*/