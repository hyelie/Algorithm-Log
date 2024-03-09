#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> db(4*4*4*4);

set<string> zero_index_columns = {"cpp", "backend", "junior", "chicken"};
set<string> one_index_columns = {"java", "frontend", "senior", "pizza"};
set<string> two_index_columns = {"python"};

// i, j, k, l을 숫자로
int get_index(int i, int j, int k, int l){
    int cnt = 0;
    cnt += l;
    cnt += k * 4;
    cnt += j * 4 * 4;
    cnt += i * 4 * 4 * 4;
    return cnt;
}
    
int parse(string column){
    if(zero_index_columns.find(column) != zero_index_columns.end()){
        return 0;
    }
    if(one_index_columns.find(column) != one_index_columns.end()){
        return 1;
    }
    if(two_index_columns.find(column) != two_index_columns.end()){
        return 2;
    }
    
    return -1;
}

void parse_and_push(string input){
    istringstream iss(input);
    
    string language, part, experience, food;
    int point;
    iss >> language >> part >> experience >> food >> point;
    
    // 해당하는 쪽에 하나,
    // db[parse(language)][parse(part)][parse(experience)][parse(food)].insert(point);
    int index_lan = parse(language);
    int index_part = parse(part);
    int index_exp = parse(experience);
    int index_food = parse(food);

    // 모든 조건에 하나씩 넣어야 함.
    vector<string> all_cases = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                                "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    for(string cases : all_cases){
        // cases[i] == 0이면 모든 조건에 넣음.
        int temp_index_lan = index_lan;
        if(cases[0] == '0'){
            temp_index_lan = 3;
        }
        
        int temp_index_part = index_part;
        if(cases[1] == '0'){
            temp_index_part = 2;
        }
        
        int temp_index_exp = index_exp;
        if(cases[2] == '0'){
            temp_index_exp = 2;
        }
        
        int temp_index_food = index_food;
        if(cases[3] == '0'){
            temp_index_food = 2;
        }
        
        int db_index = get_index(temp_index_lan, temp_index_part, temp_index_exp, temp_index_food);        
        db[db_index].push_back(point);
    }
}

int get_result(string query){
    istringstream iss(query);
    
    string language, part, experience, food;
    int point;
    
    string buffer;
    vector<string> parsed_query;
    while(getline(iss, buffer, ' ')){
        if(buffer == "and") continue;
        parsed_query.push_back(buffer);
    }
    language = parsed_query[0];
    part = parsed_query[1];
    experience = parsed_query[2];
    food = parsed_query[3];
    point = stoi(parsed_query[4]);
    
    int language_index = parse(language); if(language == "-") language_index = 3;
    int part_index = parse(part); if(part == "-") part_index = 2;
    int experience_index = parse(experience); if(experience == "-") experience_index = 2;
    int food_index = parse(food); if(food == "-") food_index = 2;
    
    int db_index = get_index(language_index, part_index, experience_index, food_index);       
    vector<int> &peoples = db[db_index];
    int result = peoples.end() - lower_bound(peoples.begin(), peoples.end(), point);
    return result;
}

vector<int> solution(vector<string> infos, vector<string> queries) {
    // push info
    for(string info : infos){
        parse_and_push(info);
    }
    
    for(int i = 0; i<db.size(); i++){
        sort(db[i].begin(), db[i].end(), less<int>());
    }
    
    // get result
    vector<int> answer;
    for(string query : queries){
        answer.push_back(get_result(query));
    }
    
    return answer;
}

/*
DB index ... !?

4 * 3 * 3 * 3 * 50000
각 조건마다 하나씩 집어넣고, 전체 조건에도 집어넣고.
*/