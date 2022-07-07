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

    

    
    return 0;
}