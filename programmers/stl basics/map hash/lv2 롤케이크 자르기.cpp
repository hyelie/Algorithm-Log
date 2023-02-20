#include <string>
#include <vector>
#include <map>

using namespace std;

void addTopping(map<int, int> &m, int topping){
    if(m.find(topping) == m.end()){
        m[topping] = 1;
    }
    else m[topping]++;
}

void removeTopping(map<int, int>& m, int topping){
    m[topping]--;
    if(m[topping] == 0) m.erase(topping);
}

int solution(vector<int> topping) {
    map<int, int> left, right;
    for(int t : topping) addTopping(right, t);
    
    int answer = 0;
    
    for(int t : topping){
        removeTopping(right, t);
        addTopping(left, t);
        if(left.size() == right.size()) answer++;
    }
    
    return answer;
}

// two-pointer ? sliding window ? 