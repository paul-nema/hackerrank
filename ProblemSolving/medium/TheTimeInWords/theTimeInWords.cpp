//  https://www.hackerrank.com/challenges/the-time-in-words/

#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords( int h, int m ) {
    vector< std::string > hour = { "", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine", "ten", "eleven", "twelve", "one" };

    std::string tm;

    switch( m ) {
        case 0:
            tm = hour[ h ] + " o' clock";
            break;

        case 15:
            tm = "quarter past " + hour[ h ];
            break;

        case 30:
            tm = "half past " + hour[ h ];
            break;

        case 45:
            tm = "quarter to " + hour[ h + 1 ];
            break;

        default:
            if( m == 1 || m == 59 ) {
                tm = "one minute "
                    + ( ( m == 1 ) ? "past " + hour[ h ] : "to " + hour[ h + 1 ] );

                break;
            } 
            
            std::string near( ( m < 30 ) ? "minutes past " : "minutes to " );

            if ( m < 10 || 60 - m < 10 ) {  //  handle up to 9 after or before next hour
                tm = hour[ ( m < 10 ) ? m : 60 - m ] + ' '
                    + near + hour[ ( m < 10 ) ? h : h + 1 ];

            } else if( m < 20 || 60 - m < 20 ) {    //  handle up to 19 after or before next hour
                vector< std::string > teen = { "ten", "eleven", "twelve", "thirteen", "fourteen",
                    "fifthteen", "sixteen", "seventeen", "eighteen", "ninteen" };

                tm = teen[ ( m < 20 ) ? m - 10 : 50 - m ] + ' ' +
                    near + hour[ ( m < 20 ) ? h : h + 1 ];

            } else if( m < 30 ) {
                tm = "twenty " + hour[ m - 20 ];

                if( m != 20 ) {
                    tm += ' ';
                }
                tm += near + hour[ ( m < 30 ) ? h : h + 1 ];

            } else {
                tm = "twenty " + hour[ 40 - m ];
               
                if( 40 - m != 0 ) {
                    tm += ' ';
                }
                tm += near + hour[ h + 1 ];
            }
    }

    return( tm );
}

int main() {
    int h;
    cin >> h;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    int m;
    cin >> m;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );

    string result = timeInWords( h, m );

    cout << result << "\n";

    return 0;
}
