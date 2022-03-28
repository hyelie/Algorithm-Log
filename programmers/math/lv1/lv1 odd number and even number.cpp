// 홀수와 짝수

#include <string>
#include <vector>

using namespace std;

string solution(int num) {

    return num%2 == 0 ? "Even" : "Odd";
}