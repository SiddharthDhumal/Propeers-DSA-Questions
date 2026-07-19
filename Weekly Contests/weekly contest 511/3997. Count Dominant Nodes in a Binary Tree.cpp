#include <bits/stdc++.h>
using namespace std;


 // Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
// TC - O(n) -> n is number of nodes and SC - O(h) -> height of tree
private:
    int dominantNodes = 0;
    int postOrderTraversal(TreeNode* root){
         if(root==nullptr)
            return INT_MIN;
        
         int leftMax = postOrderTraversal(root->left);
         int rightMax = postOrderTraversal(root->right);

         int currentMax = max(root->val,max(leftMax,rightMax));

         if(currentMax==root->val)
             dominantNodes++;
         
         return currentMax;
    }
public:
    int countDominantNodes(TreeNode* root) {
            postOrderTraversal(root);

            return dominantNodes;
    }
};