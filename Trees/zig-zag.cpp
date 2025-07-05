#include <iostream>
#include <queue>
#include <vector>
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

vector<vector<int>> ZigZagTraversal(Node *node, vector<vector<int>> &result){
    if(node == nullptr) return result;

    queue<Node*> q;
    bool LeftToRight = true;
    q.push(node);

    while(!q.empty()){
        int size = q.size();
        vector<int> row;
        for(int i=0; i<size; i++){
            Node* N = q.front();
            q.pop();

            int index = (LeftToRight) ? i : (size - 1 - i);
            row[index] = N->data;
            if (N->left != nullptr) q.push(N->left);
            if (N->right != nullptr) q.push(N->right);
        }
        
        LeftToRight = !LeftToRight;
        result.push_back(row);
    }

}