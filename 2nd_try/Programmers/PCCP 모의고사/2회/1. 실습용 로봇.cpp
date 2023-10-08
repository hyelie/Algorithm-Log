#include <string>
#include <vector>

using namespace std;

int direction = 0; // dx, dy의 index. R이면 +1, L이면 -1
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<int> position = {0, 0};

void rotate(char command){
    if(command == 'R'){
        direction++;
        if(direction == 4) direction = 0;
    }
    else if(command == 'L'){
        direction--;
        if(direction < 0) direction = 3;
    }
}

void move(char command){
    int d = direction;
    if(command == 'B'){
        d += 2;
        d %= 4;
    } 
    position[0] += dx[d];
    position[1] += dy[d];
}

vector<int> solution(string command) {
    for(char c : command){
        if(c == 'R' || c == 'L'){
            rotate(c);
        }
        else if(c == 'G' || c == 'B'){
            move(c);
        }
    }
    return position;
}