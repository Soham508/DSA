#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool getPath(Node *node, vector<int> &res, int n){
    if(!node) return false;

    res.push_back(node->data);

    if(n == node->data) return true;

    if(getPath(node->left, res, n) || getPath(node->right, res, n)){
       return true;
    }

    res.pop_back();
    return false;
}