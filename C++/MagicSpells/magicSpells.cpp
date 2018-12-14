//  https://www.hackerrank.com/challenges/magic-spells/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Spell {
private:
  string scrollName;

public:
  Spell() : scrollName("") {}
  Spell(string name) : scrollName(name) {}
  virtual ~Spell() {}
  string revealScrollName() { return scrollName; }
};

class Fireball : public Spell {
private:
  int power;

public:
  Fireball(int power) : power(power) {}
  void revealFirepower() { cout << "Fireball: " << power << endl; }
};

class Frostbite : public Spell {
private:
  int power;

public:
  Frostbite(int power) : power(power) {}
  void revealFrostpower() { cout << "Frostbite: " << power << endl; }
};

class Thunderstorm : public Spell {
private:
  int power;

public:
  Thunderstorm(int power) : power(power) {}
  void revealThunderpower() { cout << "Thunderstorm: " << power << endl; }
};

class Waterbolt : public Spell {
private:
  int power;

public:
  Waterbolt(int power) : power(power) {}
  void revealWaterpower() { cout << "Waterbolt: " << power << endl; }
};

class SpellJournal {
public:
  static string journal;
  static string read() { return journal; }
};
string SpellJournal::journal = "";

void counterspell( Spell *spell ) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    if( Frostbite *cs = dynamic_cast< Frostbite* >( spell ) ) {
        cs->revealFrostpower();
        return;
    }

    if( Fireball *cs = dynamic_cast< Fireball* >( spell ) ) {
        cs->revealFirepower();
        return;
    }

    if( Thunderstorm *cs = dynamic_cast< Thunderstorm* >( spell ) ) {
        cs->revealThunderpower();
        return;
    }

    if( Waterbolt *cs = dynamic_cast< Waterbolt* >( spell ) ) {
        cs->revealWaterpower();
        return;
    }

    //  to solve I used this ref:  https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

    auto scrollName{ spell->revealScrollName() };   //  easier to work work a local var

    std::vector< std::vector< int > > lcs( scrollName.size() + 1,   //  init all to 0
            std::vector< int >( SpellJournal::journal.size() + 1, 0 ) );

    for( unsigned long x{ 1 }; x <= scrollName.size(); ++x ) {
        for( unsigned long y{ 1 }; y <= SpellJournal::journal.size(); ++y ) {
            if( scrollName[ x - 1 ] == SpellJournal::journal[ y - 1 ] ) {
                lcs[ x ][ y ] = lcs[ x - 1 ][ y - 1 ] + 1;
            } else {
                lcs[ x ][ y ] = std::max( lcs[ x ][ y - 1 ], lcs[ x - 1 ][ y ] );
            }
        }
    }

    std::cout << lcs[ scrollName.size() ][ SpellJournal::journal.size() ] << "\n";
}

class Wizard {
public:
  Spell *cast() {
    Spell *spell;
    string s;
    cin >> s;
    int power;
    cin >> power;
    if (s == "fire") {
      spell = new Fireball(power);
    } else if (s == "frost") {
      spell = new Frostbite(power);
    } else if (s == "water") {
      spell = new Waterbolt(power);
    } else if (s == "thunder") {
      spell = new Thunderstorm(power);
    } else {
      spell = new Spell(s);
      cin >> SpellJournal::journal;
    }
    return spell;
  }
};

int main() {
  int T;
  cin >> T;
  Wizard Arawn;
  while (T--) {
    Spell *spell = Arawn.cast();
    counterspell(spell);
  }
  return 0;
}
