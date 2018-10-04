//  https://www.hackerrank.com/challenges/30-binary-search-trees/

#include <cstddef>
#include <iostream>

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

  int getHeight(Node *root) {
    // Write your code here
    return( 1
        + std::max( root->left == NULL ? -1 : getHeight( root->left ),
            root->right == NULL ? -1 : getHeight( root->right )
          )
    ); 
  }

}; // End of Solution

int main() {
  Solution myTree;
  Node *root = NULL;
  int t;
  int data;

  cin >> t;

  while (t-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }
  int height = myTree.getHeight(root);
  cout << height;

  return 0;
}
