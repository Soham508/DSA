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

void dfs(Node* node, int hd, int lvl, map<int, vector<pair<int, int>>>& nodes) {
    if (!node) return;

    nodes[hd].push_back({lvl, node->data});

    dfs(node->left, hd - 1, lvl + 1, nodes); 
    dfs(node->right, hd + 1, lvl + 1, nodes); 
}

vector<vector<int>> verticalTraversal(Node* root) {
    map<int, vector<pair<int, int>>> nodes;  // hd -> [(level, value)]
    dfs(root, 0, 0, nodes);

    vector<vector<int>> result;
    for (auto& [hd, vec] : nodes) {
       
        sort(vec.begin(), vec.end());
        vector<int> column;
        for (auto& [lvl, val] : vec)
            column.push_back(val);
        result.push_back(column);
    }

    return result;
}
