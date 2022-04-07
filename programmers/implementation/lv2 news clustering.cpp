// 뉴스 클러스터링

#include <string>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

void make_char_pair_vector(string str, multiset<string> &s){
    string temp;
    for(int i = 0; i<str.length()-1; i++){
        temp = str.substr(i, 2);
        if(isalpha(temp[0]) && isalpha(temp[1])){
            temp[0] = tolower(temp[0]);
            temp[1] = tolower(temp[1]);
            s.insert(temp);
        }
    }
    return;
}

int solution(string str1, string str2) {
    multiset<string> s1, s2;
    make_char_pair_vector(str1, s1);
    make_char_pair_vector(str2, s2);
    
    if(s1.size() == 0 && s2.size() == 0) return 65536;
    
    multiset<string> Intersection, Union;
    multiset<string>::iterator iter1 = s1.begin(), iter2 = s2.begin();
    
    // intersection
    while(iter1 != s1.end() && iter2 != s2.end()){
        if(*iter1 == *iter2){
            Intersection.insert(*iter1);
            iter1++; iter2++;
        } else if(*iter1 > *iter2){
            iter2++;
        } else if(*iter1 < *iter2){
            iter1++;
        }
    }
    
    // union
    iter1 = s1.begin(); iter2 = s2.begin();
    while(iter1 != s1.end() && iter2 != s2.end()){
        if(*iter1 == *iter2){
            Union.insert(*iter1);
            iter1++; iter2++;
        } else if(*iter1 > *iter2){
            Union.insert(*iter2);
            iter2++;
        } else if(*iter1 < *iter2){
            Union.insert(*iter1);
            iter1++;
        }
    }
    while(iter1 != s1.end()){
        Union.insert(*iter1);
        iter1++;
    }
    while(iter2 != s2.end()){
        Union.insert(*iter2);
        iter2++;
    }
    
    /*for(string s : Intersection){
        cout<<s<<endl;
    }cout<<endl;
    for(string s : Union){
        cout<<s<<endl;
    }cout<<endl;*/

    
    return floor((long double)65536 * Intersection.size() / Union.size());
}

/*

J(A, B) = |A INTERSECT B| / |A UNION B|. 몫이 0인 경우는 1로 정의.(A, B가 모두 공집합인 경우)
다중집합에 대해서도 동일함.
2글자씩 띄워서 다중집합의 원소로 만듬. 공백/숫자/특문이 있는 경우 그 글자쌍 버림.
모두 소문자로 처리.
소수값이므로 65536을 곱하고 정수부만 출력.

*/