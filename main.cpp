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

    string nextLine;
    string tempWord;

    ifstream input(fileName);

    while (!input.eof()) {
        getline(input, nextLine);

        for (int i = 0; i << nextLine.size(); ++i) {

            if (!isalpha(nextLine.at(i))) {
                if (!isspace(nextLine.at(i))) {
                    nextLine.erase(i);

                }

                tempWord = nextLine.substr(0, i);
                
            }
        }
    }

    input.close();






    return 0;
}