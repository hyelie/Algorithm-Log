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

bool canPrinceWin(vector<int> princess, vector<int> prince){
    int winCount = 0;
    for(int i = 0; i<3; i++){
        if(prince[i] > princess[i]) winCount++;
    }

    if(winCount >= 2) return true;
    else return false;
}

void solve(int a, int b, int c, int d, int e){
    set<int> deck;
    for(int i = 1; i<=52; i++) deck.insert(i);

	vector<int> princess(3), prince(3, 0);
    princess[0] = a; princess[1] = b; princess[2] = c;
    prince[0] = d; prince[1] = e;
    for(int c : princess) deck.erase(c);
    for(int c : prince) deck.erase(c);

    // princess permutation
    sort(princess.begin(), princess.end(), less<int>());
    vector<vector<int>> princessDecks;
    do{
        princessDecks.push_back(princess);
    }while(next_permutation(princess.begin(), princess.end()));
    int allCount = princessDecks.size();

    // 제일 낮은 카드 할당할 것임. 이후 모든 경우의 수에서 왕자가 승리하면 그 카드 주면 됨.
    for(int card : deck){
        prince[0] = d; prince[1] = e; prince[2] = card;

        // prince permutation
        sort(prince.begin(), prince.end(), less<int>());
        vector<vector<int>> princeDecks;
        do{
            princeDecks.push_back(prince);
        }while(next_permutation(prince.begin(), prince.end()));

        // 모든 경우 판정에서, 단 하나라도 질 수 있다면 다음 카드로 감.
        // 실수 : 6개를 1:1 대응이 아니라 6*6으로 2중for문 돌렸어야 했음.
        bool canLose = false;
        for(vector<int> princessDeck : princessDecks){
            for(vector<int> princeDeck : princeDecks){
                if(canPrinceWin(princessDeck, princeDeck) == false){
                    canLose = true;
                    break;
                }
            }
            if(canLose == true) break;
        }

        if(canLose == true) continue;
        else{
            cout<<card<<'\n';
            return;
        }
    }
    // 승리 불가
    cout<<"-1\n";
    return;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
    int a, b, c, d, e;
    while(1){
        cin>>a>>b>>c>>d>>e;
        if(a + b + c + d + e == 0) break;
        solve(a, b, c, d, e);
    }

	return 0;
}