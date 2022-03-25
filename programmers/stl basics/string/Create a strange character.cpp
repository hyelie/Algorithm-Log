#include <string>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

string solution(string s) {
    bool sp = false;
    int length = s.size();
    
    for(int i = 0; i< length; i++){
        if(s[i] != ' ') sp = true;
        if(sp){
            for(int j = 0; s[i] != ' ' && i < length;){
                if(j%2 == 0)s[i] = toupper(s[i]);
                else s[i] = tolower(s[i]);
                i++; j++;
            }
            sp = false;
        }
    }
    
    return s;
}