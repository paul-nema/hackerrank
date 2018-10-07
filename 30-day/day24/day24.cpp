//  https://www.hackerrank.com/challenges/30-linked-list-deletion/

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int d) {
    data = d;
    next = NULL;
  }
};

class Solution {
public:
  Node *removeDuplicates(Node *head) {
    // Write your code here
      if( head == NULL ) { 
          return( head );
      }

      Node *h = head;
      Node *rm = nullptr;

      while( h && h->next ) {
          if( h->data == h->next->data ) {  //  duplicate
              rm = h->next;

              h->next = h->next->next;

              delete rm;    // clean up memory

              continue; //  don't advance, next may be a repeat too
          }

          h = h->next;
      }

      return( head );
  }

  Node *insert(Node *head, int data) {
    Node *p = new Node(data);
    if (head == NULL) {
      head = p;

    } else if (head->next == NULL) {
      head->next = p;

    } else {
      Node *start = head;
      while (start->next != NULL) {
        start = start->next;
      }
      start->next = p;
    }
    return head;
  }
  void display(Node *head) {
    Node *start = head;
    while (start) {
      cout << start->data << " ";
      start = start->next;
    }
  }
};

int main() {
  Node *head = NULL;
  Solution mylist;
  int T, data;
  cin >> T;
  while (T-- > 0) {
    cin >> data;
    head = mylist.insert(head, data);
  }
  head = mylist.removeDuplicates(head);

  mylist.display(head);
}
