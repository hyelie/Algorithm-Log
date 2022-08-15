#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredients) {
    int answer = 0;

    vector<int> cur;
    for(int i = 0, cidx = 0; i<ingredients.size(); i++){
        cur.push_back(ingredients[i]);
        int csize = cur.size();
        if(csize >= 4){
            if(cur[csize-1] == 1 && cur[csize-2] == 3 && cur[csize-3] == 2 && cur[csize-4] == 1){
                cur.erase(cur.begin() + csize - 4, cur.end());
                answer++;
            }
        }
    }

    return answer;
}