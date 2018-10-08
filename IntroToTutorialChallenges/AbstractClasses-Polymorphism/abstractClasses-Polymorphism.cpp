//  https://www.hackerrank.com/challenges/abstract-classes-polymorphism/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Node {
  Node *next;
  Node *prev;
  int value;
  int key;
  Node(Node *p, Node *n, int k, int val)
      : prev(p), next(n), key(k), value(val){};
  Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {

protected:
  map<int, Node *> mp;            // map the key to the node in the linked list
  int cp;                         // capacity
  Node *tail;                     // double linked list tail pointer
  Node *head;                     // double linked list head pointer
  virtual void set(int, int) = 0; // set function
  virtual int get(int) = 0;       // get function
};

class LRUCache : public Cache {
    public:
        LRUCache( int capacity ) {
            cp = capacity;

            head = tail = nullptr;
        }

        void set( int key, int val ) {
            auto it = mp.find( key );

            if( it == mp.end() ) {  //  new Node
                cacheMiss( key, val );
            } else {    //  duplicate
                cacheHit( key, val );
            }

        }

        int get( int key ) {
            auto it = mp.find( key );

            if( it == mp.end() ) {  //  Not in cache
                return( -1 );
            }

            return( it->second->value );
        }

    private:
        void cacheHit( int key, int val ) {
            auto tmpHead( head );

            if( mp[ key ] == tail ) {   //  moving tail
                tail = mp[ key ]->prev;
            }

            head = mp[ key ];
            head->value = val;
            head->next = tmpHead;

            tmpHead->prev = head;
            mp[ key ]->prev->next = mp[ key ]->next;
        }

        void cacheMiss( int key, int val ) {
            auto n = new Node( nullptr, nullptr, key, val );

            if( head == nullptr ) { //  start linked list
                mp[ key ] = head = tail = n;

                return;
            }

            n->next = head;

            mp[ key ] = head = head->prev = n;

            if( mp.size() > cp ) {  //  new node exceeds capacity - drop last node
                auto deleteMe = tail;

                tail->prev->next = nullptr;
                tail = tail->prev;

                mp.erase( deleteMe->key );

                delete deleteMe;
            }
        }
};

int main() {
  int n, capacity, i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for (i = 0; i < n; i++) {
    string command;
    cin >> command;
    if (command == "get") {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    } else if (command == "set") {
      int key, value;
      cin >> key >> value;
      l.set(key, value);
    }
  }
  return 0;
}
