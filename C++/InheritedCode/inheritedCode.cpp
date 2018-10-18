//  https://www.hackerrank.com/challenges/inherited-code/

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

std::string errMsg; //  Save err msg when what() goes out of scope

class BadLengthException: public exception {
    public:
        BadLengthException( int num ): n( num ) {}

        virtual const char* what() const noexcept {
            ::errMsg = std::to_string( n ) ;

            return( errMsg.c_str() );
        }

    private:
        int n;
};

bool checkUsername(string username) {
  bool isValid = true;
  int n = username.length();
  if (n < 5) {
    throw BadLengthException(n);
  }
  for (int i = 0; i < n - 1; i++) {
    if (username[i] == 'w' && username[i + 1] == 'w') {
      isValid = false;
    }
  }
  return isValid;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    string username;
    cin >> username;
    try {
      bool isValid = checkUsername(username);
      if (isValid) {
        cout << "Valid" << '\n';
      } else {
        cout << "Invalid" << '\n';
      }
    } catch (BadLengthException e) {
      cout << "Too short: " << e.what() << '\n';
    }
  }
  return 0;
}
