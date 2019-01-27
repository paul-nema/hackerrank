//  https://www.hackerrank.com/challenges/mars-exploration/

#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration( const std::string &s ) {
    auto cnt{ 0 };

    for( unsigned long x{ 0 }; x < s.size(); ++x ) {
        switch( x % 3 ) {   //  not the most efficient but very maintainable
            case 0:
                if( s[ x ] != 'S' ) {
                    ++cnt;
                }

                break;
            case 1:
                if( s[ x ] != 'O' ) {
                    ++cnt;
                }

                break;
            default:    //  case 2
                if( s[ x ] != 'S' ) {
                    ++cnt;
                }
        }
    }

    return( cnt );
}

int main() {
    string s;
    getline( cin, s );

    int result = marsExploration( s );

    cout << result << "\n";

    return 0;
}
