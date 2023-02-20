#include <string>
#include <vector>

using namespace std;

string ABLE = "Yes", DISABLE = "No";

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    bool canMake = true;
    for(int goalidx = 0, idx1 = 0, idx2 = 0; goalidx < goal.size();){
        if(idx1 < cards1.size() && cards1[idx1] == goal[goalidx]){
            idx1++;
            goalidx++;
        }
        else if(idx2 < cards2.size() && cards2[idx2] == goal[goalidx]){
            idx2++;
            goalidx++;
        }
        else{
            canMake = false;
            break;
        }
    }

    return canMake ? ABLE : DISABLE;
}