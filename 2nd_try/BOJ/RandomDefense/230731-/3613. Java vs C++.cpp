#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <cmath>
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

////////////////////// write your code below

/*
	_와 대문자가 같이 있으면 안됨
	_만 있으면 _를 지우고 _ 다음 걸 대문자로 바꿈
	_가 없고 대문자만 있으면 대문자 앞에 _ 넣고 소문자로 변경
	*/

int JAVA = 0, CPP = 1, ERROR = 2;

int judge(string s){
	if(s[0] == '_' || s[s.length()-1] == '_' || isupper(s[0])) return ERROR;
	for(int i = 1; i<s.length(); i++){
		if(s[i] == '_' && s[i-1] == '_') return ERROR;
	}

	bool isJava = false, isCPP = false;
	for(char c : s){
		if(isupper(c)) isJava = true;
		if(c == '_') isCPP = true;
	}

	if(isJava && isCPP) return ERROR;
	if(isJava) return JAVA;

	string s_backup = s;
	for(char &c : s_backup) c = tolower(c);
	if(s == s_backup) return CPP;

	if(isCPP) return CPP;
	return ERROR;
}

	string java2cpp(string s){
		string result = "";
		for(char c : s){
			if(isupper(c)){
				result += "_";
				result += tolower(c);
			}
			else result += c;
		}
		return result;
	}

	string cpp2java(string s){
		string result = "";
		for(int i = 0; i<s.length(); i++){
			if(s[i] == '_'){
				result += toupper(s[i+1]);
				i++;
			}
			else result += s[i];
		}
		return result;
	}

void solve(){
	string s; cin>>s;
	int type = judge(s);
	if(type == JAVA) s = java2cpp(s);
	else if(type == CPP) s = cpp2java(s);
	else s = "Error!";
	cout<<s;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();	

	return 0;
}