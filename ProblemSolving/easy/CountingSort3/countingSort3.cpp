//  https://www.hackerrank.com/challenges/countingsort3/

#include <iostream>
#include <string>
#include <vector>

const int MAX_ARRAY_SIZE{ 100 };

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto n{ 0 }, x{ 0 };

    std::string str;

    std::vector< int > sorted( MAX_ARRAY_SIZE, 0 );

    std::cin >> n;

    while( n-- ) {
        std::cin >> x;
        std::getline( std::cin, str );

        sorted[ x ]++;
    }

    for( unsigned long x{ 1 }; x < sorted.size(); ++x ) {
        sorted[ x ] += sorted[ x - 1 ];

        std::cout << sorted[ x - 1 ] << " ";
    }

    std::cout << sorted[ sorted.size() - 1 ] << std::endl;

    return 0;
}
