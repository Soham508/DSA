#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


void printSubtreeNodes(Node* node, int k) {
    if (node == nullptr || k < 0)
        return;
    if (k == 0) {
        cout << node->data << " ";
        return;
    }
    printSubtreeNodes(node->left, k - 1);
    printSubtreeNodes(node->right, k - 1);
}


int nodesAtDistanceK(Node* root, Node* target, int k) {
    if (root == nullptr)
        return -1;

    
    if (root == target) {
        printSubtreeNodes(root, k);
        return 1;
    }

    int dl = nodesAtDistanceK(root->left, target, k);
    if (dl != -1) {
        if (dl == k)
            cout << root->data << " ";
        else
            printSubtreeNodes(root->right, k - dl - 1); 
        return 1 + dl;
    }

   
    int dr = nodesAtDistanceK(root->right, target, k);
    if (dr != -1) {
        if (dr == k)
            cout << root->data << " ";
        else
            printSubtreeNodes(root->left, k - dr - 1);
        return 1 + dr;
    }

    return -1; 
}
