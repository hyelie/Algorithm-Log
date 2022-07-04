#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

long long arr[300001];

int main() {
	string str;
	stack<char> ques;
	long long num = 0;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '?') {
			ques.push(str[i]);
		}
		if (str[i] == ':') {
			ques.pop();
			if (ques.empty())
				num = (num + 1) % 1000000007;
		}
	}

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= num; i++) {
		for (int j = 0; j < i; j++) {
			arr[i] += (arr[j] * arr[i - 1 - j]) % 1000000007;
		}
	}

	cout << arr[num];
	return 0;
}