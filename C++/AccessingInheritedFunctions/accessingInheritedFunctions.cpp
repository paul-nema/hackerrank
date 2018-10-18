//  https://www.hackerrank.com/challenges/accessing-inherited-functions/

#include <iostream>

using namespace std;

class A {
   public:
    A() { callA = 0; }

   private:
    int callA;
    void inc() { callA++; }

   protected:
    void func( int& a ) {
        a = a * 2;
        inc();
    }

   public:
    int getA() { return callA; }
};

class B {
   public:
    B() { callB = 0; }

   private:
    int callB;
    void inc() { callB++; }

   protected:
    void func( int& a ) {
        a = a * 3;
        inc();
    }

   public:
    int getB() { return callB; }
};

class C {
   public:
    C() { callC = 0; }

   private:
    int callC;
    void inc() { callC++; }

   protected:
    void func( int& a ) {
        a = a * 5;
        inc();
    }

   public:
    int getC() { return callC; }
};

class D: public A, public B, public C {
    int val;

   public:
    // Initially val is 1
    D() { val = 1; }

    // Implement this function
    void update_val( int new_val ) {
        auto x( new_val );
        auto times5( 0 );
        auto times3( 0 );
        auto times2( 0 );

        while( ( x % 5 ) == 0 ) {
            x /= 5;

            ++times5;
        }

        while( ( x % 3 ) == 0 ) {
            x /= 3;

            ++times3;
        }

        while( ( x % 2 ) == 0 ) {
            x /= 2;

            ++times2;
        }

        for( x = 0; x < times2; ++x ) { //  re-use x
            A::func( val );
        }

        for( x = 0; x < times3; ++x ) {
            B::func( val );
        }

        for( x = 0; x < times5; ++x ) {
            C::func( val );
        }
    }

    // For Checking Purpose
    void check( int );  // Do not delete this line.
};

void D::check( int new_val ) {
    update_val( new_val );
    cout << "Value = " << val << endl
         << "A's func called " << getA() << " times " << endl
         << "B's func called " << getB() << " times" << endl
         << "C's func called " << getC() << " times" << endl;
}

int main() {
    D d;
    int new_val;
    cin >> new_val;
    d.check( new_val );
}
