#include "Query.h"
#include "TextQuery.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using std::set;
using std::string;
using std::map;
using std::vector;
using std::cerr;
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;

int main()
{
    ifstream ifs("D://±à³Ì´úÂë//c++//C++ primer//TextQuery//TextQuery//TextQuery//storyDataFile.txt");
    TextQuery file(ifs);

    /*
    // iterate with the user: prompt for a word to find and print results
    do {
        string sought;
        if (!get_word(sought)) break;

        // find all the occurrences of the requested string
        // define synonym for the line_no set 
        Query name(sought);
        const auto results = name.eval(file);
        cout << "\nExecuting Query for: " << name << endl;

        // report no matches
        print(cout, results) << endl;
    } while (true);  // loop indefinitely; the exit is inside the loop
    */
    while (true) {
        string sought1, sought2, sought3;
        if (!get_words(sought1, sought2)) break;
        cout << "\nenter third word: ";
        cin >> sought3;
        // find all the occurrences of the requested string
        Query q = Query(sought1) & Query(sought2)
            | Query(sought3);
        cout << "\nExecuting Query for: " << q << endl;
        const auto results = q.eval(file);
        // report matches
        print(cout, results);
    }
    return 0;
}
