#include <bits/stdc++.h>

using namespace std;

bool checkBeauty( string &s, int pos, int len ) {
    string first = s.substr( pos, len );
    if( first[ 0 ] == '0' ) {
        return( false );
    }

    string second = s.substr( pos + len, len );
    if( second[ 0 ] == '0' ) {
        return( false );
    }

    int firstNum = std::atoi( first );
    int secondNum = std::atoi( second );

    if( secondNum - firstNum == 1 ) {
        return( true );
    }

    return( false );
}


// Complete the separateNumbers function below.
void separateNumbers(string &s) {
    if( s[0] == '0') {
        cout << "NO\n";
        return;
    }

    bool isBeautiful = false;

    int charLen = 1;

    string first;
    string second;

    for( long unsigned x = 0; x < s.size(); ++x ) {
        for( auto y = 1; ; ++y ) {
            if( ( isBeautiful = checkBeauty( s, x, y ) ) == false ) {
                continue;
            }
        }
        while( ( x + 1 ) * 2 <= s.size() ) {

        }
    }
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}

