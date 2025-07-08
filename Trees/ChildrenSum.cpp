/*
Given a binary tress, modify it so every node has value equals to sum of its child nodes value, with contraint that, 
we can only add tree node value by +1 as many times as we want, but can not decrease the value
*/

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


void ChangeTree(Node* node){
    if(node == nullptr) return;
    int childSum = 0;

    if(node->left) childSum += node->left->data;
    if(node->right) childSum += node->right->data;

    if(childSum >= node->data) node->data = childSum;
    else{
        if(node->left) node->left->data = node->data;
        if(node->right) node->right->data = node->data;
    }

    ChangeTree(node->left);
    ChangeTree(node->right);

    int total = 0;
    if(node->left) total += node->left->data;
    if(node->right) total += node->right->data;

    if(node->left || node->right) node->data = total;
}