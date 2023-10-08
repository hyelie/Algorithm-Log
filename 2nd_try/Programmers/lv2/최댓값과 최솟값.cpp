#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>

using namespace std;

string solution(string s) {
    int min_v = INT_MAX;
    int max_v = INT_MIN;
    
    istringstream iss(s);
    string buffer;
    while(getline(iss, buffer, ' ')){
        int v;
        if(buffer[0] == '-'){
            v = stoi(buffer.substr(1));
            v *= -1;
        }
        else{
            v = stoi(buffer);
        }
        
        min_v = min(min_v, v);
        max_v = max(max_v, v);
        
    }
    
    return to_string(min_v) + " " + to_string(max_v);
}