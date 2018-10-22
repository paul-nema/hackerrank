//  https://www.hackerrank.com/challenges/attribute-parser/

#include <iostream>
#include <vector>
#include <map>
#include <regex>


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto n( 0 );
    auto q( 0 );
    auto x( 0 );
    auto level( 0 );

    std::string input( "" );
    std::string tagChain( "" );
    std::string matchedStr( "" );

    std::cin >> n >> q;
    std::cin.ignore( std::numeric_limits< std::streamsize >::max(), '\n' );

    std::map< std::string, std::string > nmVal;

    std::regex startTag( "<(\\w+)" );
    std::regex endTag( "</(\\w+)>" );
    std::regex attribute( "(\\w+ = \"[\\w|\\d|.|%|!|@|#|$|^]+\")" );    //  match att = val
    std::regex values( "(\\w+) = \"([\\w|\\d|.|%|!|@|#|$|^]+)\"" ); //  get attribute and value

    std::smatch tag;

    for( x = 0; x < n; ++x ) {
        std::getline( std::cin, input );

        std::regex_search( input, tag, startTag );

        if( ! tag.empty() ) {
            if( level++ == 0 ) {
                tagChain = tag[ 1 ].str();
            } else {
                tagChain += "." + tag[ 1 ].str();
            }

            while( std::regex_search( input, tag, attribute ) ) {
                matchedStr = tag.str();
                input = tag.suffix().str();    //  reset for next pattern match

                std::regex_search( matchedStr, tag, values );

                if( ! tag.empty() ) {
                    nmVal[ tagChain + "~" + tag[ 1 ].str() ] = tag[ 2 ].str();
                }
            }

            continue;
        }   //  OK need to process end tag. Poor problem description

        std::regex_search( input, tag, endTag );    //  process end tags

        if( ! tag.empty() ) {
            size_t pos = tagChain.find( tag[ 1 ].str() );

            if ( pos != std::string::npos ) {
                if( --level == 0 ) {
                    tagChain.clear();
                } else {
                    tagChain.erase( pos - 1, tag[ 1 ].str().length() + 1 );
                }
            }
        }
    }

    for( x = 0; x < q; ++x ) {
        std::getline( std::cin, input );

        auto it = nmVal.find( input );

        if( it == nmVal.end() ) {
            std::cout << "Not Found!\n";
        } else {
            std::cout << it->second << "\n";
        }
    }
}
