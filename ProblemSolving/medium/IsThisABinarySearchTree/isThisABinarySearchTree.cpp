// Support code not provided so only saving what I wrote

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  
 *
 * The Node struct is defined as follows:
 *  struct Node {
 *          int data;
 *                  Node* left;
 *                          Node* right;
 *                              }
 *                              */

#include <climits>

bool checkBST( Node* root, int minInt = INT_MIN, int maxInt = INT_MAX ) {
    if( root == NULL ) {
        return true;
    }

    if ( root->data < minInt || root->data > maxInt ){
        return false;
    }

    return( checkBST( root->left, minInt, root->data -1 ) &&
        checkBST( root->right, root->data + 1, maxInt ) );
}
