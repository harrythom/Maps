#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    string fileName = argv[1];

    vector <string> tokens;
    set <string> uniques;
    map <string, string> wordMap;
    
    string nextLine;

    ifstream input(fileName);

    if (input.is_open()) {

        while (!input.eof()) {
            getline(input, nextLine);

            istringstream iss(nextLine);
            string token;

            while (iss >> token) {
                string noPunct = "";

                for (auto &c : token) {
                    if (isalpha(c)) {
                        noPunct += c;
                    }
                }
                tokens.push_back(noPunct);
                uniques.insert(noPunct);
            }
        }
        input.close();
    }
    else {
        cout << "Could not open the specified file.";
        return 0;
    }

    cout << "Num words: " << tokens.size() << endl;
    cout << "Num unique words: " << uniques.size() << endl;


    //------------Writing to new files-----------//

    ofstream output("Set.txt");

    for (set <string>::iterator it = uniques.begin(); it != uniques.end(); ++it) {
        output << *it << endl;
    }

    output.close();

    ofstream output("Vector.txt");

    for (int i = 0; i < tokens.size(); ++i) {
        output << tokens.at(i) << endl;
    }

    output.close();


    //-------------Creating wordmap and writing it to file----------------//

    string last = "";

    for (int i = 0; i < tokens.size(); ++i) {
        wordMap[last] = tokens.at(i);
        last = tokens.at(i);
    }

    


    //------------

    string state = "";
    
    for(int i = 0; i < 100; i++){
        cout << wordMap[state] << " ";
        state = wordMap[state];
    }
    
    cout << endl;

    //





    



    
    return 0;
}