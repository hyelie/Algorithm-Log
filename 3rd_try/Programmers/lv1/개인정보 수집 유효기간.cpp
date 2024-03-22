#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

map<string, int> term_map;

string add_period_to_date(string &date, int period){
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    month += period;
    year += (month-1) / 12;
    month = (month-1) % 12 + 1;
    
    string syear = to_string(year);
    string smonth = to_string(month); if(smonth.length() == 1) smonth = "0" + smonth;
    string sday = to_string(day); if(sday.length() == 1) sday = "0" + sday;
    
    return syear + "." + smonth + "." + sday;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    // term map init
    for(string term : terms){
        string name; int period;
        istringstream iss(term);
        iss >> name >>period;
        term_map[name] = period;
    }
    
    // privacies
    vector<int> answer;
    for(int i = 0; i<privacies.size(); i++){
        string date, term_name;
        istringstream iss(privacies[i]);
        iss >> date >> term_name;
        
        if(add_period_to_date(date, term_map[term_name]) <= today){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}