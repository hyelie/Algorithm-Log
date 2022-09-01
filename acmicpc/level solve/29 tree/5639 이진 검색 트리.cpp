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


int n;
vector<int> preorder;

void post(int start, int end){
	if(start > end) return;

	int root = preorder[start];

	int right_begin;
	for(right_begin = start+1; right_begin <= end; right_begin++){
		if(preorder[right_begin] > root){
			break;
		}
	}

	post(start+1, right_begin-1);
	post(right_begin, end);
	cout<<root<<'\n';
}

/*

pre
50 30 24 5 28 45 98 52 60
30 24 5 28 45 - 50 - 98 52 60			
24 5 28 - 30 - 45 		- 50 - 		98 - 52 60
...

preorder에서, 처음 게 root
root보다 작으면 left, 크면 right
root보다 처음으로 큰 vertex index = right_begin이라 둠
이건 preorder vertex를 {value, index} 형태로 정렬 후 upper_bound로 찾을 것.

root index + 1 ~ right_begin - 1까지 div&conq
right_begin ~ end까지 div&conq

*/

void solve(){
	int input;
	int i = 0;
	while(true){
		cin>>input;
		if(cin.eof() == true){
			break;
		}
		preorder.push_back(input);
	}


	n = preorder.size();
	
	post(0, n-1);
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}