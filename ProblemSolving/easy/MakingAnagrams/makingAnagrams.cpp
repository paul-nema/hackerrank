//  https://www.hackerrank.com/challenges/making-anagrams/

#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string &s1, string &s2) {
    // Use the C++ lib to do this.  Start by sorting the strings
    sort( begin( s1 ), end( s1 ) );
    sort( begin( s2 ), end( s2 ) );

    int smallestStr = min( s1.size(), s2.size() );

    // Create string with a buffer to hold intersection
    string intersection;

    set_intersection( begin( s1 ), end( s1 ),
            begin( s2 ), end( s2 ),
            back_inserter( intersection ) );

    return( ( s1.size() - intersection.size() ) + ( s2.size() - intersection.size() ) );
}

int main()
{
    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    cout << result << "\n";

    return 0;
}

