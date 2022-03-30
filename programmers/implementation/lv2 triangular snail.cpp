// 삼각 달팽이

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> v(n, vector<int>(n));
    int tempn = n, type = 0, rowidx = 0, colidx = 0, length = n, origin_n = n;
    int total_num = n * (n+1) / 2;
    
    // type 0 : col만 채움
    // type 1 : row만 채움
    // type 2 : 좌상단으로 가면서 대각으로 채움
    
    for(int i = 1; i<=total_num; i++){
        v[rowidx][colidx] = i;
        
        if(type == 0){
            rowidx++;
        } else if(type == 1){
            colidx++;
        } else{
            rowidx--; colidx--;
        }
        
        length--;
        if(length == 1){
            type = (type+1)%3;    
            length = n;
            n--;
        }
        
    }
    
    
    
    vector<int> a;
    for(int i = 0; i<origin_n; i++){
        for(int j = 0; j<=i; j++){
            a.push_back(v[i][j]);
        }
    }
    return a;
}









/*
vector<int> solution(int n) {
    vector<vector<int>> tri(n, vector<int>(n, 0));

    int i = 0, j = 0;

    int num = 1;
    int totalnum = n * (n + 1) / 2;
    // n(n+1)/2

    int mode = 0;
    // mode=0 : 아래 : i++, j그대로
    // mode=1 : 오른쪽 : i그대로, j++
    // mode=2 : 좌상단 : i--, j--
    int len = n;

    while (num != totalnum+1) {
        int templen = len;
        len--;
        switch (mode) {
        case 0:
            while (templen--) {
                tri[i][j] = num;
                num++;
                i++;
                mode = 1;
            }
            i--; j++;
            break;
        case 1:
            while (templen--) {
                tri[i][j] = num;
                num++;
                j++;
                mode = 2;
            }
            j--; j--; i--;
            break;
        case 2:
            while (templen--) {
                tri[i][j] = num;
                num++;
                i--; j--;
                mode = 0;
            }
            i++; j++; i++;
            break;
        }
    }

    vector<int> answer;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) break;
            answer.push_back(tri[i][j]);
        }
    }



    return answer;
}
*/
// 끝나고 다음 인덱스로 넘어가는걸 못했음.