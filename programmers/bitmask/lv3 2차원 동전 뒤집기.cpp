#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> board;
int rsize, csize = 0, answer = INT_MAX;

void flipRowK(board& b, int k){
    for(int i = 0; i<csize; i++){
        b[k][i] = 1 - b[k][i];
    }
}

void flipColK(board& b, int k){
    for(int i = 0; i<rsize; i++){
        b[i][k] = 1 - b[i][k];
    }
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    if(beginning == target) return 0;
    
    rsize = beginning.size(); csize = beginning[0].size();
    
    for(int i = 0; i < (1 << rsize); i++){
        board rowtemp = beginning;
        int rcount = 0;
        // row flip
        for(int k = 0; k<rsize; k++){
            if(1 & (i >> k)){
                flipRowK(rowtemp, k);
                rcount++;
            }
        }
        
        for(int j = 0; j < (1 << csize); j++){
            board coltemp = rowtemp;
            int ccount = 0;
            for(int k = 0; k<csize; k++){
                if(1 & (j >> k)){
                    flipColK(coltemp, k);
                    ccount++;
                }
            }
            if(coltemp == target){
                answer = min(answer, rcount + ccount);
            }
        }
    }
    
    
    return answer == INT_MAX ? -1 : answer;
}