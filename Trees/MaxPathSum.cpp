#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int solve(Node* node, int& res) {
    if (node == nullptr) return 0;

    int left = max(0, solve(node->left, res));   
    int right = max(0, solve(node->right, res)); 

    int temp = node->data + left + right;     res = max(res, temp);                 

    return node->data + max(left, right); 
}