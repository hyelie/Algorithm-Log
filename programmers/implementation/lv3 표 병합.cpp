#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <set>

using namespace std;
typedef pair<int, int> pii;

// input을 공백 기준으로 split
vector<string> splitString(string input) {
    vector<string> result;
    istringstream iss(input);
    string buffer;
 
    while (getline(iss, buffer, ' ')) result.push_back(buffer);

    return result;
}

vector<set<pii>> linked; // linked : 병합된 cell들
// update 시 linked의 모든 set을 순회. 모든 set에 [r, c]가 있다면 그 set의 모든 값에 값 변경
// merge 시 linked의 모든 set을 순회. 모든 set에 [r1, c1]과 [r2, c2]가 없으면 새로 만들어 넣음. 있는 경우 거기에 추가.
// unmerge 시 linked의 모든 set에 순회. 모든 set의 값에 공백을 넣어주고 [r1, c1] 자리에 거기 있던 값 가지게 함
string EMPTY = "EMPTY";
int tableSize = 51, NOT_FOUND = -1;
vector<vector<string>> table(tableSize, vector<string>(tableSize, EMPTY));
vector<string> printResult;

// [r, c]가 속해있는 linked set의 index. 없을 시 NOT_FOUND return
int findLinkedIndex(int r, int c){
    for(int i = 0; i<linked.size(); i++){
        for(pii cell : linked[i]){
            if(cell.first == r && cell.second == c){
                return i;
            }
        }
    }
    return NOT_FOUND;
}

void UpdateOP1(int r, int c, string value){
    int linkedIdx = findLinkedIndex(r, c);
    
    if(linkedIdx == NOT_FOUND) table[r][c] = value;
    else{
        for(pii cell : linked[linkedIdx]){
            table[cell.first][cell.second] = value;
        }
    }
}

void UpdateOP2(string value1, string value2){
    for(int i = 0; i < tableSize; i++){
        for(int j = 0; j < tableSize; j++){
            if(table[i][j] == value1) table[i][j] = value2;
        }
    }
}

/*
두 셀 모두 값을 가진 경우 -> r1, c1의 값으로 : merge 후 UpdateOp1 실행하면 될듯?
하나만 값을 가진 경우 : 그 값을 가짐
case가 많네...

1 병합 O + 2 병합 O : 2를 전부 빼서 1에 넣고, 값을 가지고 있는 경우 처리
1 병합 O + 2 병합 X : 2를 1에 넣고 값을 가지고 있는 경우 처리 UpdateOp1
1 병합 X + 2 병합 O : 1을 2의 set에 넣고 값을 가지고 있는 경우 처리
1 병합 X + 2 병합 X : 새로운 set 만들기 + 값 가지고 있는 경우 처리
*/
void MergeOP(int r1, int c1, int r2, int c2){

    int leftLinkedIdx = findLinkedIndex(r1, c1);    
    int rightLinkedIdx = findLinkedIndex(r2, c2);    
    string leftValue = table[r1][c1], rightValue = table[r2][c2];
    
    if(leftLinkedIdx != NOT_FOUND && rightLinkedIdx != NOT_FOUND){
        if(leftLinkedIdx == rightLinkedIdx) return; // *** 같은 경우...
        for(pii cell : linked[rightLinkedIdx]){
            linked[leftLinkedIdx].insert(cell);    
        }
        linked.erase(linked.begin() + rightLinkedIdx);
    }
    else if(leftLinkedIdx != NOT_FOUND && rightLinkedIdx == NOT_FOUND){
        linked[leftLinkedIdx].insert({r2, c2});
    }
    else if(leftLinkedIdx == NOT_FOUND && rightLinkedIdx != NOT_FOUND){
        linked[rightLinkedIdx].insert({r1, c1});
    }
    else{ // leftLinkedIdx == NOT_FOUND && rightLinkedIdx == NOT_FOUND
        set<pii> cells; cells.insert({r1, c1}); cells.insert({r2, c2});
        linked.push_back(cells);
    }
    
    if(leftValue == EMPTY && rightValue != EMPTY){
        UpdateOP1(r1, c1, rightValue);
    }
    else{
        UpdateOP1(r1, c1, leftValue);
    }
}

void UnmergeOP(int r, int c){
    string prevValue = table[r][c];
    int linkedIdx = findLinkedIndex(r, c);   
    if(linkedIdx != NOT_FOUND){
        for(pii cell : linked[linkedIdx]){
            table[cell.first][cell.second] = EMPTY;
        }
        linked.erase(linked.begin() + linkedIdx);
    }
    
    table[r][c] = prevValue;
}

void PrintOP(int r, int c){
    printResult.push_back(table[r][c]);
}

vector<string> solution(vector<string> commands) {
    for(string command : commands){
        vector<string> params = splitString(command);
        if(params[0] == "UPDATE"){
            if(params.size() == 4){ // 1번
                int r = stoi(params[1]), c = stoi(params[2]);
                UpdateOP1(r, c, params[3]);
            }
            else{ // 2번
                UpdateOP2(params[1], params[2]);
            }
        }
        else if(params[0] == "MERGE"){ // 3번
            int r1 = stoi(params[1]), c1 = stoi(params[2]);
            int r2 = stoi(params[3]), c2 = stoi(params[4]);
            MergeOP(r1, c1, r2, c2);
        }
        else if(params[0] == "UNMERGE"){ // 4번
            int r = stoi(params[1]), c = stoi(params[2]);
            UnmergeOP(r, c);
        }
        else if(params[0] == "PRINT"){ // 5번
            int r = stoi(params[1]), c = stoi(params[2]);
            PrintOP(r, c);
        }
        
        cout<<command<<endl;
        for(int i = 1; i<5; i++){
            for(int j = 1; j<5; j++){
                cout<<table[i][j]<<' ';
            }cout<<endl;
        }
        cout<<endl;
    }
    

    return printResult;
}

/*
reference같은거 쓰면 쉽게 안 풀릴라나? 응 안돼~ unmerge 있어~
merge 상태에 관리되고 있는 것들을 찾아야 할 듯?

command 길이 1000
r, c 50 -> 2500
모든 command에서 모든 r, c순회해도 2500000
*/