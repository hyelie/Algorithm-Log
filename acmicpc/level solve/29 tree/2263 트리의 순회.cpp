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
vector<int> inorder, postorder, inorder_index;

void preorder(int in_start, int in_end, int post_start, int post_end){
	if(in_end < in_start || post_end < post_start) return;
	 int root = postorder[post_end];
	 int in_root_index = inorder_index[root];
	 cout<<root<<' ';

	 int left_size = (in_root_index - 1) - in_start + 1;

	 preorder(in_start, in_root_index-1, post_start, post_start + left_size - 1);
	 preorder(in_root_index+1, in_end, post_start + left_size, post_end-1);
}

/*
postorder의 end가 root임
inorder에서 root를 찾고, 그 왼쪽에 있는 것과 그 오른쪽에 있는 것들이 left/right child임
 -> inorder의 root index를 쉽게 찾기 위해 inorder vertex의 index mapper를 둠.
postorder를 div&conq 해서 inorder의 left/right로 나눔
inorder의 root index - start index + 1이 left child size
postorder의 start index ~ start index + left child size - 1가 post의 left child
postorder의 start index ~ left child size ~ end index -1이 post의 right child
postorder의 left, right로 div
*/

void solve(){
	int n; cin>>n;
	inorder.resize(n), postorder.resize(n), inorder_index.resize(n+1);
	for(int i = 0; i<n; i++){
		cin>>inorder[i];
		inorder_index[inorder[i]] = i; // inorder_index[i] : inorder[i]의 index
	}
	for(int i = 0; i<n; i++){
		cin>>postorder[i];
	}

	preorder(0, n-1, 0, n-1);
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}