//  https://www.hackerrank.com/challenges/strong-password/

#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string &password) {
    // Return the minimum number of characters to make the password strong
    string specialChars( "!@#$%^&*()-+" );

    auto issues = 4;

    bool digit = false;
    bool lowercase = false;
    bool uppercase = false;
    bool special = false;

    for( auto x = 0; x < password.size(); ++ x) {
        if( digit == false && isdigit( password[ x ] ) ) {
                digit = true;
                --issues;
        }
        if( lowercase == false && islower( password[ x ] ) ) {
                lowercase = true;
                --issues;
        }
        if( uppercase == false && isupper( password[ x ] ) ) {
                uppercase = true;
                --issues;
        }
        if( special == false && specialChars.find( password[ x ] ) != std::string::npos ) {
                special = true;
                --issues;
        }
    }

    if( n < 6 && issues < ( 6 - n ) ) {
        return( 6 - n );
    }

    return( issues );

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    cout << answer << "\n";

    return 0;
}

