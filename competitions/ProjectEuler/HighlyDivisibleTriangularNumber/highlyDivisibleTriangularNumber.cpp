#include <algorithm>
#include <cmath>
#include <iostream>

//  http://mathforum.org/library/drmath/view/55843.html
//  If prime factors are a**x, b**y, c**z, ...n
//  then the number of divisors = (x+1)*(y+1)*(z+1)*...n

unsigned long divisors( unsigned long num ) {
    auto count{ 0 };

    if( ! ( num & 1 ) ) {   //  only try if even number
        while( num % 2 == 0 ) {
            ++count;

            num /= 2;
        }
    }

    auto divisors{ count + 1 };

    for( unsigned long div{ 3 }; div <= std::sqrt( num ); div += 2 ) {
        count = 0;

        while( num % div == 0 ) {
            ++count;

            num /= div;
        }

        divisors *= count + 1;
    }

    return( num > 2 ? divisors * 2 : divisors );
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long sum{ 0 };

    auto divisor{ 0 };
    auto T{ 0 }, N{ 0 }, x{ 0 };

    std::cin >> T;

    while( T-- ) {
        std::cin >> N;

        while( divisor <= N ) {
            sum += ++x;

            divisor = divisors( sum );
        }

        std::cout << sum << "\n";

        sum = divisor = x = 0;
    }

    return 0;
}
