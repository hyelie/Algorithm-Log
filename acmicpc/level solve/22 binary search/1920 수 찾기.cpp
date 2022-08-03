/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

bool bsearch(int target){
    int start = 0, end = arr.size()-1, mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] < target){
            start = mid + 1;
        }
        else{ // arr[mid] > target
            end = mid - 1;
        }
    }
    return false;
}

int main()
{   
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int N; cin>>N;
    arr.resize(N);
    for(int i= 0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    
    int M; cin>>M;
    while(M--){
        int target;
        cin>>target;
        cout<<bsearch(target)<<'\n';
    }

    return 0;
}
