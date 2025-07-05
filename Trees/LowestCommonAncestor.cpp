#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
              if(root == nullptr) return root;
              if(root == p || root == q) return root;

              TreeNode* left = lowestCommonAncestor(root->left, p, q);
              TreeNode* right = lowestCommonAncestor(root->right, p, q);

              if(right == nullptr) return left;
              if(left == nullptr) return right;

              else return root;
    }
