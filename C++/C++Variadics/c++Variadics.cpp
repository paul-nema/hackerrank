//  https://www.hackerrank.com/challenges/cpp-variadics/

#include<iostream>

using namespace std;

template < bool... digits >
auto reversed_binary_value() {
    auto result{ 0 };
    auto power{ 1 };

    for( bool bin: { digits... } ) {
        if( bin == true ) { //  Only care about 1's
            result += power;
        }

        power *= 2;
    }

    return( result );
}

template <int n, bool... digits>
struct CheckValues {
    static void check( int x, int y ) {
        CheckValues<n - 1, 0, digits...>::check( x, y );
        CheckValues<n - 1, 1, digits...>::check( x, y );
    }
};

template <bool... digits>
struct CheckValues<0, digits...> {
    static void check( int x, int y ) {
        int z = reversed_binary_value<digits...>();
        std::cout << ( z + 64 * y == x );
    }
};

int main() {
    int t;
    std::cin >> t;

    for ( int i = 0; i != t; ++i ) {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check( x, y );
        cout << "\n";
    }
}
