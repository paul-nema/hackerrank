//  https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
  int data;
  SinglyLinkedListNode *next;

  SinglyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
  }
};

class SinglyLinkedList {
public:
  SinglyLinkedListNode *head;

  SinglyLinkedList() { this->head = nullptr; }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep ) {
  while (node) {
    cout << node->data;

    node = node->next;

    if (node) {
      cout << sep;
    }
  }
}

void free_singly_linked_list(SinglyLinkedListNode *node) {
  while (node) {
    SinglyLinkedListNode *temp = node;
    node = node->next;

    free(temp);
  }
}

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *head, int data) {
    if( head == nullptr ) {
        return( new SinglyLinkedListNode( data ) );
    }

    auto ttmp = head;   //  need to return head so use a temp var

    while( ttmp->next ) {   //  find last node
        ttmp = ttmp->next;
    }

    ttmp->next = new SinglyLinkedListNode( data );

    return( head );
}

int main() {
  SinglyLinkedList *llist = new SinglyLinkedList();

  int llist_count;
  cin >> llist_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i = 0; i < llist_count; i++) {
    int llist_item;
    cin >> llist_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode *llist_head = insertNodeAtTail(llist->head, llist_item);

    llist->head = llist_head;
  }

  print_singly_linked_list(llist->head, "\n");
  cout << "\n";

  free_singly_linked_list(llist->head);

  return 0;
}
