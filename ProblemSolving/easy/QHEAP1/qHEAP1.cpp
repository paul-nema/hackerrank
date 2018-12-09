//  https://www.hackerrank.com/challenges/qheap1/

#include <bits/stdc++.h>

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto queries{ 0 };
    auto instruction{ 0 };
    auto val{ 0 };

    std::priority_queue< int, std::vector< int >, std::greater< int > > pq;

    std::map< int, bool > deleted;  //  keep track of what's deleted

    std::cin >> queries;

    while( queries-- ) {
        std::cin >> instruction;

        switch( instruction ) {
            case 1: //  Add an element val to the heap
                std::cin >> val;

                pq.push( val );
                deleted[ val ] = false;

                break;

            case 2: //  Delete the element val from the heap
                std::cin >> val;

                deleted[ val ] = true;

                break;

            case 3: //  Print the minimum of all the elements in the heap
                while( deleted[ pq.top() ] ) {  //  remove previous min deleted values from pq
                    deleted[ pq.top() ] = false;    //  reinit the val in case its used again

                    pq.pop();   //  bye byw
                }

                std::cout << pq.top() << "\n";

                break;
        }
    }

    return 0;
}
