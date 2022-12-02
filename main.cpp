#include "StringSet.h"

int main() {
    char response;
    cout << "Hello!\nDo you want to open a file? (y/n)\n";
    cin >> response;
    response = tolower(response);
    while (response != 'y' && response != 'n') {
        cout << "Please enter only y or n!\n";
        cin >> response;
    }
    if (response == 'y') {
        string filename;
        cout << "Please enter the name of the file you want to open:\n";
        cin >> filename;
        ifstream file(filename);
        if (file.is_open()) {
            StringSet tstt(file);
            tstt.printWordSet();
            file.close();
        }
    }

    //Other Test Cases;
    StringSet tst;
    tst.addString("Chocolate ice cream, chocolate milk, and chocolate bars are delicious.");
    tst.printWordSet();
    tst.removeString("some word ice cream");
    tst.printWordSet();
    cout << tst.getNumOfWords() << endl;
    tst.clearSet();
    tst.printWordSet();
    cout << tst.getNumOfWords() << endl;
    StringSet tst2("some, word, again, ice");
    cout << tst.computeSimilarity(tst2) << endl;
    StringSet common, both;
    both = tst + tst2;
    common = tst * tst2;
    common.printWordSet();
    both.printWordSet();

    return 0;
}
