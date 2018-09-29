#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Write Your Code Here
    int first( 0 );
    int second( 0 );
    cin >> first >> second;
    if( second == 0 ) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> second;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::string number;

    for( auto x( first ); x <= second; ++x ) {
        if( x > 9 ) {
            if( x & 1 ) {
                number = "odd\n";
            } else {
                number = "even\n";
            }
        } else if( x == 9 ) {
            number = "nine\n";
        } else if( x == 8 ) {
            number = "eight\n";
        } else if( x == 7 ) {
            number = "seven\n";
        } else if( x == 6 ) {
            number = "six\n";
        } else if( x == 5 ) {
            number = "five\n";
        } else if( x == 4 ) {
            number = "four\n";
        } else if( x == 3 ) {
            number = "three\n";
        } else if( x == 2 ) {
            number = "two\n";
        } else {
            number = "one\n";
        }

        std::cout << number;
    } 


    return 0;
}
