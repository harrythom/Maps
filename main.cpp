#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <ctime>
#include <list>

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

//     ofstream output("Set.txt");

//     for (set <string>::iterator it = uniques.begin(); it != uniques.end(); ++it) {
//         output << *it << endl;
//     }
//
//     output.close();
//
//     ofstream output2("Vector.txt");
//
//     for (int i = 0; i < tokens.size(); ++i) {
//         output2 << tokens.at(i) << endl;
//     }
//
//    output.close();


    //-------------Creating wordmap and writing it to file----------------//

    string last = "";

    for (int i = 0; i < tokens.size(); ++i) {
        wordMap[last] = tokens.at(i);
        last = tokens.at(i);
    }


    //------------Test for the "learned" words: Part 4-----------//

//    string state = "";
//
//    for (int i = 0; i < 100; i++){
//        cout << wordMap[state] << " ";
//        state = wordMap[state];
//    }
//
//    cout << endl;

    //----------Another Test: Part 5-----------//

//    map <string, vector<string>> wordmap;
//    string state2 = "";
//
//    for (int i = 0; i < tokens.size(); ++i) {
//        wordmap[state2].push_back(tokens.at(i));
//        state2 = tokens.at(i);
//    }
//
    srand(time(NULL));
//    string state3 = "";
//    for (int i = 0; i < 100; i++) {
//        int ind = rand() % wordmap[state3].size();
//        cout << wordmap[state3][ind] << " ";
//        state3 = wordmap[state3][ind];
//    }
//    cout << endl;


    //-----------And another test: Part 6-------//


    int M = 2;

    map<list<string>, vector<string> > wordmap2;
    list<string> state5;
    for (int i = 0; i < M; i++) {
        state5.push_back("");
    }

    for (int i = 0; i < tokens.size(); ++i) {
        wordmap2[state5].push_back(tokens.at(i));
        state5.push_back(tokens.at(i));
        state5.pop_front();
    }

    state5.clear();

    for (int i = 0; i < M; ++i) {
        state5.push_back("");
    }

    for (int i = 0; i < 100; ++i) {
        int ind = rand() % wordmap2[state5].size();
        cout << wordmap2[state5][ind]<<" ";
        state5.push_back(wordmap2[state5][ind]);
        state5.pop_front();
    }




    return 0;
}