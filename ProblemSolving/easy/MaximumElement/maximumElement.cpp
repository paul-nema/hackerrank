//  https://www.hackerrank.com/challenges/qheap1/

#include <bits/stdc++.h>

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto queries{ 0 };
    auto val{ 0 };

    std::stack< long int > st;   //  LIFO structure
    std::stack< long int > largest;   //  use to track largest value

    std::cin >> queries;

    while( queries-- ) {
        std::cin >> val;

        switch( val ) {
            case 1: //  Add to the stack
                std::cin >> val;

                st.push( val );

                if( largest.empty() ) {
                    largest.push( val );    //  add initial value
                } else {
                    if( val > largest.top() ) {
                        largest.push( val );
                    } else {
                        largest.push( largest.top() );  //  keep largest val going
                    }
                }

                break;

            case 2: //  Delete top element
                st.pop();
                largest.pop();

                break;

            default: //  Print
                if( ! largest.empty() ) {
                    std::cout << largest.top() << "\n";
                }
        }
    }

    return 0;
}
