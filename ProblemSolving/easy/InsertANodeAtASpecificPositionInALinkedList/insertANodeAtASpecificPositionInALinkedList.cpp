//  https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/

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
  SinglyLinkedListNode *tail;

  SinglyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data) {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
    }

    this->tail = node;
  }
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

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode *insertNodeAtPosition( SinglyLinkedListNode *head, int data, int position ) {
    auto begin( head );
    auto targetPosition( 0 );

    while( head && ++targetPosition < position ) {
        head = head->next;
    }

    SinglyLinkedListNode * const node = new SinglyLinkedListNode( data );

    if( position == 0 ) {   //  insert at the front
        node->next = begin;
        begin = node;
    } else {
        node->next = head->next;
        head->next = node;
    }

    return( begin );
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

    llist->insert_node(llist_item);
  }

  int data;
  cin >> data;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int position;
  cin >> position;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  SinglyLinkedListNode *llist_head =
      insertNodeAtPosition(llist->head, data, position);

  print_singly_linked_list(llist_head, " ");
  cout << "\n";

  free_singly_linked_list(llist_head);

  return 0;
}
