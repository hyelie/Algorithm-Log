#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    vector<string> arr = {"수", "박"};
    string answer = "";
    for(int i = 0; i<n; i++){
        answer += arr[i%2];
    }
    return answer;
}