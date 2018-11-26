//  https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/

#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
public:
  int data;
  DoublyLinkedListNode *next;
  DoublyLinkedListNode *prev;

  DoublyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList {
public:
  DoublyLinkedListNode *head;
  DoublyLinkedListNode *tail;

  DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data) {
    DoublyLinkedListNode *node = new DoublyLinkedListNode(node_data);

    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
      node->prev = this->tail;
    }

    this->tail = node;
  }
};

void print_doubly_linked_list(DoublyLinkedListNode *node, string sep ) {
  while (node) {
    cout << node->data;

    node = node->next;

    if (node) {
      cout << sep;
    }
  }
}

void free_doubly_linked_list(DoublyLinkedListNode *node) {
  while (node) {
    DoublyLinkedListNode *temp = node;
    node = node->next;

    free(temp);
  }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *head, int data) {
    DoublyLinkedListNode *nodePtr{ head };

    if( data < head->data ) {
        head = new DoublyLinkedListNode( data );
        head->next = nodePtr;

        return( head );
    }

    DoublyLinkedListNode *tmp{ head };

    while( tmp ) {
        if( data >= tmp->data && ( tmp->next == nullptr || data <= tmp->next->data ) ) {
            break;
        }

        tmp = tmp->next;
    }

    nodePtr = tmp->next;
    tmp->next = new DoublyLinkedListNode( data );
    tmp->next->prev = tmp;
    tmp->next->next = nodePtr;

    return( head );
}

int main() {
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    DoublyLinkedList *llist = new DoublyLinkedList();

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

    DoublyLinkedListNode *llist1 = sortedInsert(llist->head, data);

    print_doubly_linked_list(llist1, " ");
    cout << "\n";

    free_doubly_linked_list(llist1);
  }

  return 0;
}
