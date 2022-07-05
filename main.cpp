#include <iostream>
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
    string tempWord;

    ifstream input(fileName);

    while (!input.eof()) {
        getline(input, nextLine);

        for (int i = 0; i < nextLine.size(); ++i) {
            if (isalpha(nextLine.at(i)) == 0) {
                if (isspace(nextLine.at(i)) == false) {
                    nextLine.erase(i);
                }
            }
        }

        while (nextLine.find(" ") != string::npos) {
            tempWord = nextLine.substr(0, nextLine.find(" "));
            nextLine.erase(0, (nextLine.find(" ") + 1));

            tokens.push_back(tempWord);
            uniques.insert(tempWord);
        }

        tempWord = nextLine;

        tokens.push_back(tempWord);
        uniques.insert(tempWord);
    }

    input.close();

    cout << "Num words: " << tokens.size() << endl;
    cout << "Num unique words: " << uniques.size() << endl;

    ofstream output("Words.txt");

    for (int i = 0; i < tokens.size(); ++i) {
        output << tokens.at(i) << endl;
    }

    output.close();


    // string last;

    // for (int i = 0; i < tokens.size(); ++i) {
    //     wordMap[last] = tokens.at(i);
    //     last = tokens.at(i);
    // }

    

    
    return 0;
}