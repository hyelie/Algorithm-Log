#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num_removed_zeros = 0;
int num_binary_translation = 0;

string removeZero(string x){
    int total = (int) x.length();
    string result = "";
    for(char c : x){
        if(c == '1') result += "1";
    }
    int num_ones = result.length();
    num_removed_zeros += total - num_ones;
    return result;
}

string decimalToBinary(int x){
    num_binary_translation++;
    
    string result = "";
    while(x){
        result += to_string(x % 2);
        x /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> solution(string s) {
    while(s != "1"){
        int len = (int) removeZero(s).length();
        s = decimalToBinary(len);
    }
    return {num_binary_translation, num_removed_zeros};
}