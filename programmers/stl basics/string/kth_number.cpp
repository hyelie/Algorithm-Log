#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    int command_size = commands.size();
    vector<int> ans(command_size);
    for(int i = 0; i<command_size; i++){
        vector<int> subarr;
        subarr.assign(array.begin()+commands[i][0]-1, array.begin()+commands[i][1]);
        sort(subarr.begin(), subarr.end());
        ans[i] = subarr[commands[i][2]-1];
    }
    
    return ans;
    
}