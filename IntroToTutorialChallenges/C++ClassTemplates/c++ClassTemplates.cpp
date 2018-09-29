//  https://www.hackerrank.com/challenges/c-class-templates/
//  failed with a timeout using C++14 so downgraded to C++ and passed

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/*Write the class AddElements here*/
template <class T>
class AddElements {
        T element;
    public:
        AddElements ( T arg ) : element( arg ) { }

        T add ( T arg ) { return( element + arg ); }
};

template <>
class AddElements < std::string > {
        std::string &element;
    public:
        AddElements ( std::string  &arg ) : element( arg ) { }

        std::string &concatenate ( std::string &arg ) {
            element += arg;
            return( element );
        }
};

int main() {
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    string type;
    cin >> type;
    if (type == "float") {
      double element1, element2;
      cin >> element1 >> element2;
      AddElements<double> myfloat(element1);
      cout << myfloat.add(element2) << endl;
    } else if (type == "int") {
      int element1, element2;
      cin >> element1 >> element2;
      AddElements<int> myint(element1);
      cout << myint.add(element2) << endl;
    } else if (type == "string") {
      string element1, element2;
      cin >> element1 >> element2;
      AddElements<string> mystring(element1);
      cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
