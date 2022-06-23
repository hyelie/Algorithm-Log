#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;



int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);

	string s;
	cin>>s;
	set<string> latin_set;
	latin_set.insert("c=");
	latin_set.insert("c-");
	latin_set.insert("d-");
	latin_set.insert("lj");
	latin_set.insert("nj");
	latin_set.insert("s=");
	latin_set.insert("z=");

	int num_letter = 0;
	for(int i = 0; i<s.length(); i++){
		if(i + 2 < s.length()){
			if(s.substr(i, 3) == "dz="){
				i += 2;
			}
		}
		if(i + 1 < s.length()){
			if(latin_set.find(s.substr(i, 2)) != latin_set.end()){
				i += 1;
			}
		}
		num_letter++;
		
	}
	cout<<num_letter;
	
	return 0;
}