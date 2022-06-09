// 길 찾기 게임

#include <string>
#include <typeinfo>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct node{
    node *left, *right, *parent;
    int x, num;
};

typedef pair<int, int> pii;

void preorder(node* cur_node, vector<int>& result){
    if(cur_node == NULL) return;
    result.push_back(cur_node->num);
    preorder(cur_node->left, result);
    preorder(cur_node->right, result);
}

void postorder(node* cur_node, vector<int>& result){
    if(cur_node == NULL) return;
    postorder(cur_node->left, result);
    postorder(cur_node->right, result);
    result.push_back(cur_node->num);
    return;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    map<int, vector<pii>, greater<int>> node_per_floor; // node_per_floor[i] : i번째 층의 노드 vector
                                          // .first : 노드 x좌표, .second : 노드 번호
    // i번째 층에 해당하는 node를 뽑기 위함
    for(int i = 0; i<nodeinfo.size(); i++){
        node_per_floor[nodeinfo[i][1]].push_back({nodeinfo[i][0], i+1});
    }
    
    map<int, vector<pii>>::iterator iter = node_per_floor.begin();
    int rootnum = (iter->second)[0].second; // root의 번호
    node *root = new node; root->parent=root; root->left = root->right = NULL; root->x=(iter->second)[0].first; root->num=rootnum; // root node 초기화
    
    for(iter++; iter != node_per_floor.end(); iter++){
        for(pii each_node : iter->second){
            node *parent = root;
            node *cur_node = new node; cur_node->x = each_node.first; cur_node->num = each_node.second; cur_node->left = cur_node->right = NULL; // cur node 초기화
            while(1){
                if(cur_node->x < parent->x){
                    if(parent->left == NULL){
                        parent->left = cur_node;
                        cur_node->parent = parent;
                        break;
                    } else{
                        parent = parent->left;
                    }
                } else if(cur_node->x > parent->x){
                    if(parent->right == NULL){
                        parent->right = cur_node;
                        cur_node->parent=parent;
                        break;
                    } else{
                        parent = parent->right;
                    }
                }
            }
        }
    }
    
    vector<int> preorder_result, postorder_result;
    preorder(root, preorder_result);
    postorder(root, postorder_result);
    vector<vector<int>> answer = {preorder_result, postorder_result};
    return answer;
}
// root는 쉽게 정할 수 있음
// root 아래도 쉽게 정할 수 있음(root보다 작은 값 : root left, root보다 큰 값 : root right)
// 어떤 점 탐색 시 - root부터 탐색, 
// 어떤 vertex보다 왼쪽 - 왼쪽으로 내려감, 오른쪽 - 오른쪽으로 내려감