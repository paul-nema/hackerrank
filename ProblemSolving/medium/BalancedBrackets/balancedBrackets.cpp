//  https://www.hackerrank.com/challenges/balanced-brackets/

#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced( string &s ) {
    std::stack< char > brackets;

    for( const auto c: s ) {
        switch( c ) {
            case '(' :  //  add to stack
            case '{' :
            case '[' :
                brackets.push( c );

                break;

            default:    //  pop a value
                if( brackets.empty() ) {
                    return( "NO" );
                }

                switch( c ) {
                    case ')':
                        if( brackets.top() != '(' ) {
                            return( "NO" );
                        }

                        break;
                    case '}':
                        if( brackets.top() != '{' ) {
                            return( "NO" );
                        }


                        break;
                    case ']':
                        if( brackets.top() != '[' ) {
                            return( "NO" );
                        }

                        break;
                }

                brackets.pop();

                break;
        }
    }

    if( brackets.empty() ) {
        return( "YES" );
    } else {
        return( "NO" );
    }
}

int main() {
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string s;
    getline(cin, s);

    string result = isBalanced(s);

    cout << result << "\n";
  }

  return 0;
}
