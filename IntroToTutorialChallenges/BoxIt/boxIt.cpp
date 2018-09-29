//  https://www.hackerrank.com/challenges/box-it/

#include <bits/stdc++.h>

using namespace std;

// Implement the class Box
// l,b,h are integers representing the dimensions of the box
class Box {
    public:

        // The class should have the following functions :

        // Constructors:
        // Box();
        // Box(int,int,int);
        // Box(Box);
        Box() {
            l = b = h = 0;
        }

        Box( int lenght, int breath, int height ) : 
            l( lenght ), b( breath ), h( height ) {
        }

        Box( Box &box ) {
            l = box.l;
            b = box.b;
            h = box.h;
        }

        // int getLength(); // Return box's length
        // int getBreadth (); // Return box's breadth
        // int getHeight ();  //Return box's height
        // long long CalculateVolume(); // Return the volume of the box

        int getLength() { return l; }
        int getBreath() { return b; }
        int getHeight() { return h; }

        long CalculateVolume() {
            return( static_cast< long >( l ) * static_cast< long >( b ) * static_cast< long >( h ) );
        }


        // Overload operator < as specified
        // bool operator<(Box& b)
        bool operator<( const Box& rhs ) const {
            if( l < rhs.l ) {
                return( true );
            } else if( b < rhs.b && l == rhs.l ) {
                return( true );
            } else if( h < rhs.h && l == rhs.l && b == rhs.b ) {
                return( true );
            }

            return( false );
        }

        // Overload operator << as specified
        // ostream& operator<<(ostream& out, Box& B)
        friend std::ostream& operator<<( std::ostream& out, const Box& box );

    private:
        int l;
        int b;
        int h;

};

std::ostream& operator<<( std::ostream& out, const Box& box ) {
    out << box.l << " " << box.b << " " << box.h;

    return( out );
}

void check2() {
  int n;
  cin >> n;
  Box temp;
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      cout << temp << endl;
    }
    if (type == 2) {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      temp = NewBox;
      cout << temp << endl;
    }
    if (type == 3) {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      if (NewBox < temp) {
        cout << "Lesser\n";
      } else {
        cout << "Greater\n";
      }
    }
    if (type == 4) {
      cout << temp.CalculateVolume() << endl;
    }
    if (type == 5) {
      Box NewBox(temp);
      cout << NewBox << endl;
    }
  }
}

int main() { check2(); }
