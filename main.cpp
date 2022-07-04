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
    string tempWord = "blank";

    ifstream input(fileName);

    while (!input.eof()) {
        getline(input, nextLine);

        for (int i = 0; i << nextLine.size(); ++i) {
            if (!isalpha(nextLine.at(i)) && !isspace(nextLine.at(i))) {
                if (nextLine.at(i) != '-') {
                    nextLine.erase(i);
                }
            }
        }
        for (int i = 0; i << nextLine.size(); ++i) {
            if (nextLine.find(" ") != string::npos) {
                tempWord = nextLine.substr(0, nextLine.find(" "));
                nextLine.erase(0, nextLine.find(" ") + 1);

            }
            else {
                tempWord = nextLine;
            }
        }
    }

    input.close();






    return 0;
}