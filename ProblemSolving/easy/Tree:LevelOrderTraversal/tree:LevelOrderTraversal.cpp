//  https://www.hackerrank.com/challenges/tree-level-order-traversal/

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution {
public:
  Node *insert(Node *root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node *cur;
      if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }
  /*
  class Node {
      public:
          int data;
          Node *left;
          Node *right;
          Node(int d) {
              data = d;
              left = NULL;
              right = NULL;
          }
  };
  */

  void levelOrder(Node *root) {
      std::deque< Node * > nodes;

      nodes.push_back( root );  //  start with the root

      while( ! nodes.empty() ) {
          std::cout << nodes.front()->data << " ";  //  print the first node

          //    Add children nodes to the end of the deque if any
          if( nodes.front()->left ) {
              nodes.push_back( nodes.front()->left );
          }

          if( nodes.front()->right ) {
              nodes.push_back( nodes.front()->right );
          }

          nodes.pop_front();    //  done with node, remove it
      }
  }

}; // End of Solution

int main() {

  Solution myTree;
  Node *root = NULL;

  int t;
  int data;

  std::cin >> t;

  while (t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.levelOrder(root);

  return 0;
}
