//  https://www.hackerrank.com/challenges/30-binary-trees/

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
class Node {
public:
  int data;
  Node *left, *right;
  Node(int d) {
    data = d;
    left = right = NULL;
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

  void levelOrder(Node *root) {
    // Write your code here
      if( root == NULL ) {
          return;
      }

      q.push( root );   //  add root to the queue

      while( ! q.empty() ) {    //  go down tree a level at a time
          Node *n = q.front();
          q.pop();

          std::cout << n->data << " ";

          if( n->left != NULL ) {   //  add next level left
              q.push( n->left );
          }

          if( n->right != NULL ) {  //  add next level right
              q.push( n->right );
          }
      }
  }

  private:
      std::queue< Node * > q;
}; // End of Solution

int main() {
  Solution myTree;
  Node *root = NULL;
  int T, data;
  cin >> T;
  while (T-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }
  myTree.levelOrder(root);
  return 0;
}
