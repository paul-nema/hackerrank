//  https://www.hackerrank.com/challenges/cpp-class-template-specialization/

#include <iostream>

using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template <typename T>
struct Traits {
    static std::string name( int );
};

template<>
std::string Traits< Fruit >::name( int index ) {
    if( index < static_cast<int>(Fruit::apple) || index > static_cast<int>(Fruit::pear) ) {
        return( "unknown" );
    }
    
    const char* const fruitNm[] = { "apple", "orange", "pear" };

    return( fruitNm[ index ] );
}

template<>
std::string Traits< Color >::name( int index ) {
    if( index < static_cast<int>(Color::red) || index > static_cast<int>(Color::orange) ) {
        return( "unknown" );
    }
    
    const char* const colorNm[] = { "red", "green", "orange" };

    return( colorNm[ index ] );
}


int main() {
  int t = 0;
  std::cin >> t;

  for (int i = 0; i != t; ++i) {
    int index1;
    std::cin >> index1;
    int index2;
    std::cin >> index2;
    cout << Traits<Color>::name(index1) << " ";
    cout << Traits<Fruit>::name(index2) << "\n";
  }
}
