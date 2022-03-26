// 내적

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int size = a.size(), sum = 0;;
    for(int i = 0; i<size; i++)
        sum += a[i] * b[i];

    return sum;
}