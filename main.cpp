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

        while (nextLine.find(" ") != string::npos) {
            tempWord = nextLine.substr(0, nextLine.find(" "));
            nextLine.erase(0, (nextLine.find(" ") + 1));

            for (int i = 0; i < tempWord.size(); ++i) {
                if (isalpha(tempWord.at(i)) == 0) {
                    tempWord.erase(i);
                }
            }

            tokens.push_back(tempWord);
            uniques.insert(tempWord);
        }

        tempWord = nextLine;

        for (int i = 0; i < tempWord.size(); ++i) {
            if (isalpha(tempWord.at(i)) == 0) {
                tempWord.erase(i);
            }
        }

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