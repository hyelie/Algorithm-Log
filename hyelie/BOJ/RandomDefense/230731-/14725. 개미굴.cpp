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
tree 만드는 문제. 
tree 만든 이후에는 traverse하는 문제. traverse할 때는 알파벳 순서대로.
*/

struct Node{
    string name;
    map<string, Node*> childs;
};

Node* root = new Node();


int N;

void traverse(Node* cur, int depth){
    for(int i = 0; i<2*depth; i++) cout<<'-';
    cout<<cur->name<<'\n';

    for(auto &elem : cur->childs){
        traverse(elem.second, depth+1);
    }
}

void solve(){
    // 입력과 동시에 tree 구성
	cin>>N;
    int K;
    for(int i = 0; i<N; i++){
        cin>>K;
        string name;
        Node* cur = root;
        for(int j = 0; j<K; j++){
            cin>>name;
            if(cur->childs.find(name) == cur->childs.end()){ // 없는 경우 새로 만들어 넣음.
                Node* new_node = new Node();
                new_node->name = name;
                cur->childs[name] = new_node;
                cur = cur->childs[name];
            } else{ // 있는 경우 기존 것으로 이동
                cur = cur->childs[name];
            }
        }
    }

    // traverse 및 출력
    for(auto &elem : root->childs){
        traverse(elem.second, 0);
    }
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}