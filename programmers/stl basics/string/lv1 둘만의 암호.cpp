#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(char c : skip){
        alphabet.erase(alphabet.find(c), 1);
    }
    for(char& c : s){
        c = alphabet[(alphabet.find(c) + index) % alphabet.length()];
    }
    return s;
}