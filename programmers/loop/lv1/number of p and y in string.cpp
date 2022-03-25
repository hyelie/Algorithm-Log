#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int number_p = 0, number_y = 0;
    for(char c : s){
        if(c == 'p' || c == 'P') number_p++;
        else if(c == 'y' || c == 'Y') number_y ++;
    }
    
    return (number_p == 0 && number_y == 0) ? true : number_p == number_y;
}