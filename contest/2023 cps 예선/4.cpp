#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char str2hex(string s)
{
    int sum = 0, mul = 8;
    for (int i = 0; i < 4; i++)
    {
        if (s[i] == '1')
            sum += mul;
        mul /= 2;
    }
    if (sum < 10)
        return '0' + sum;
    else
        return 'a' + sum - 10;
}

int main()
{
    
    /*
    // test code
    vector<string> test = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                           "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    for (string s : test)
    {
        cout << str2hex(s) << endl;
    }*/

    // 문제 조건
    vector<string> arr = {"1001", "0001", "1000", "0010", "1101", "1111", "0010",
                          "1110", "1100", "0111", "1001", "0111", "1011", "1001",
                          "1100", "1000", "1000", "1101", "1111", "0000", "1010",
                          "1111", "1000", "0111", "0111", "1011", "1110", "0101",
                          "0000", "0101", "1101", "1010", "1010", "0110", "1111",
                          "0110", "0101", "0111", "0101", "1010", "0011", "1100",
                          "1111", "0100", "1100", "0101", "0110", "0010", "0011"};
    cout << arr.size()<<endl;

    for(int i = 0; i<arr.size(); i++){
        cout<<str2hex(arr[i]);
        if((i+1)% 7 == 0) cout<<endl;
    }

    return 0;
}