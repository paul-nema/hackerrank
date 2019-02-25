//  https://www.hackerrank.com/challenges/encryption/

#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
std::string encryption( std::string &s ) {
    //  remove all spaces
    s.erase( std::remove_if( s.begin(), s.end(), ::isspace ), s.end() );

    auto column{ std::ceil( std::sqrt( s.size() ) ) };

    std::string encrypted;  //  encrypted string

    for( unsigned long x{ 0 }; x < column; ++x ) {
        for( unsigned long y{ x }; y < s.size(); y += column ) {
            encrypted.push_back( s[ y ] );
        }

        if( x < column - 1 ) {  //  avoid the space at the end
            encrypted.push_back( ' ' );
        }
    }

    return( encrypted );
}


int main() {
    string s;
    getline( cin, s );

    string result = encryption( s );

    cout << result << "\n";

    return 0;
}
