//  https://www.hackerrank.com/challenges/overload-operators/

// Operator Overloading

#include <iostream>

using namespace std;

class Complex {
public:
  int a, b;
  void input(string s) {
    int v1 = 0;
    unsigned long i = 0;
    while (s[i] != '+') {
      v1 = v1 * 10 + s[i] - '0';
      i++;
    }
    while (s[i] == ' ' || s[i] == '+' || s[i] == 'i') {
      i++;
    }
    int v2 = 0;
    while (i < s.length()) {
      v2 = v2 * 10 + s[i] - '0';
      i++;
    }
    a = v1;
    b = v2;
  }
};

Complex operator + ( Complex const &c1, Complex const &c2 ) { 
    Complex res; 

    res.a = c1.a + c2.a; 
    res.b = c1.b + c2.b; 

    return res; 
}

ostream &operator<<( ostream &output, const Complex &c ) { 
    output << c.a << "+i" << c.b;

    return output;            
}

int main() {
  Complex x, y;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  x.input(s1);
  y.input(s2);
  Complex z = x + y;
  cout << z << endl;
}
