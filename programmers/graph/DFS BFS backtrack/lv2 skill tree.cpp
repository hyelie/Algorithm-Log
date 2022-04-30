// 스킬트리

#include <set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    set<char> skill_set;
    set<string> tree_set;
    for(int i = 0; i<skill.length(); i++){
        skill_set.insert(skill[i]);
        tree_set.insert(skill.substr(0, skill.length()-i));
    }
    
    int answer = 0;
    for(string s : skill_trees){
        string result = "";
        for(char c : s){
            if(skill_set.find(c) != skill_set.end()){
                result += c;
            }
        }
        if(tree_set.find(result) != tree_set.end() || result == "") answer++;
    }
    
    return answer;
}