//  https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/

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

  /*The tree node has data, left child and right child
  class Node {
      int data;
      Node* left;
      Node* right;
  };

  */

  Node *lca( Node *root, int v1, int v2 ) {
    // Write your code here.
      if( v2 < v1 ) {
          std::swap( v1, v2 );  //  search shortest path first
      }

      auto node{ root };

      std::vector< Node * > nodes;

      while( node ) {   //  find node equal to v1 and record path in nodes
          nodes.push_back( node );

          if( node->data == v1 ) {
              break;
          }

          node = ( v1 < node->data ) ? node->left : node->right;
      }

      //    traverse path backwards looking for the lca
      for( unsigned long x{ nodes.size() - 1 }; x >= 0; --x ) {
          node = nodes[ x ];

          while( node ) {
              if( node->data == v2 ) {
                  return( nodes[ x ] );
              }

              node = ( v2 < node->data ) ? node->left : node->right;
          }
      }

      return( root );
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

  int v1, v2;
  std::cin >> v1 >> v2;

  Node *ans = myTree.lca(root, v1, v2);

  std::cout << ans->data;

  return 0;
}
