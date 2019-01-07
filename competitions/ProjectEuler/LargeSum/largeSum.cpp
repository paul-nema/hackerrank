//  https://www.hackerrank.com/contests/projecteuler/challenges/euler013

#include <iostream>
#include <string>
#include <algorithm>

//  First line contains T that denotes the number of test cases.
//  First line of each test case will contain two integers N & K.
//  Second line of each test case will contain a N digit integer.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios::sync_with_stdio( false ); //  turn off sync'ing with c libs for efficeny
    std::cin.tie( 0 );

    auto T{ 0 };

    std::cin >> T;
    std::cin.ignore( std::numeric_limits< std::streamsize >::max(), '\n' );

    std::string num;
    std::string total( 50 + ( T / 10 ) + 1, '0' );   //  init to largest possible sum size, zero fill

    char carry{ 0 };

    while (T--) {
        std::getline( std::cin, num );

        num = std::string( total.size() - num.size(), '0' ) + num;  //  match str len of total

        std::transform( num.rbegin(), num.rend(), total.rbegin(), total.rbegin(),
                [ &carry ]( char x, char y ) {  //  Yay STL!
            char z = ( x - '0' ) + ( y - '0' ) + carry;

            if ( z > 9 ) {
                carry = 1;
                z -= 10;
            } else {
                carry = 0;
            }

            return z + '0';
        });

        carry = 0;  //  re-int var
    }

    std::cout << total.substr( total.find_first_not_of( "0" ), 10 ) << std::endl;

    return 0;
}
