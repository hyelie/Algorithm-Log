/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{   
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int K, N;
    cin>>K>>N;
    vector<ll> arr(K);
    for(int i = 0; i<K; i++){
        cin>>arr[i];
    }
    // lb 구하기
    
    ll start = 0, end = 2200000000, mid;
    // upper bound
    while(start < end){
        mid = (start + end) / 2;
        ll cnt = 0;
        for(int i : arr){
            cnt += (i / mid);
        }
        if(cnt < N){ // mid만큼 잘랐을 때, cnt가 더 작으면 길이를 줄여야 함
            end = mid;
        }
        else start = mid + 1; // cnt가 더 크면 길이를 늘일 수 있음.
    }
    // 이렇게 해서 최대 길이 + 1의 값이 end가 됨.
    cout<<end - 1;

    return 0;
}
