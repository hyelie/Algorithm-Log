#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<string> answer;

    for(int i = 0; i<s.length(); i++){
        int si = i, count = 0;
        char standard = s[i];
        while(i < s.length()){
            if(s[i] == standard) count++;
            else count--;
            if(count == 0) break;
            i++;
        }
        answer.push_back(s.substr(si, i-si+1));
    }
    
    return answer.size();
}

int main(){
    solution("banana");
    solution("aaabbaccccabba");
}