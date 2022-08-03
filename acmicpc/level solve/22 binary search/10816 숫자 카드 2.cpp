/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int lower_bound(vector<int> &v, int target)
{
	int mid, start = 0, end = v.size();
    // end = v.size() - 1로 두지 말고, v.size()로 두면 not found인 경우에는 v.size() 값을 가지는 end가 리턴됨. 그렇게 하면 못 찾았는지에 대한 경우 탐색이 필요 없어지기 때문에 그렇게 두는 것이 더 합리적일 듯. 수정 할 것.
	while (start < end) 
	{
		mid = (start + end) / 2; 
		if (v[mid] >= target) // 중간값이 target보다 크거나 같은 경우 해당 index까지 end를 당김.
			end = mid; 
		else start = mid + 1; // 중간값이 target보다 작으면 mid+1까지 start를 당김.
	}
	return end;
}

int upper_bound(vector<int> &v, int target)
{
	int mid, start = 0, end = v.size();
	while (start < end) 
	{
		mid = (start + end) / 2; 
		if (v[mid] > target) // 중간값이 target보다 큰 경우 해당 index까지 end를 당김.
			end = mid;
		else start = mid + 1; // 중간값이 target보다 작으면 mid+1까지 start를 당김.
	}
	return end;
}

int main()
{   
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int N; cin>>N;
    vector<int> arr(N);
    for(int i= 0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    
    
    
    int M; cin>>M;
    while(M--){
        int target;
        cin>>target;
    
        int lb = lower_bound(arr, target), ub = upper_bound(arr, target);
        cout<<ub - lb<<' ';
    }

    return 0;
}
