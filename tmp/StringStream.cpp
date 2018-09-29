#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    std::vector< int > integers;

    std::stringstream strOfNums;

    strOfNums.str( str );

    auto num( 0 );
    auto c( ' ' );

    while( strOfNums >> num ) {
        integers.push_back( num );
        strOfNums >> c; //  handle comma
    }
    
    return( integers );
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(unsigned long i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
