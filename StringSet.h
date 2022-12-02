#ifndef TASK3_STRINGSET_H
#define TASK3_STRINGSET_H

#include <iostream>
#include <set>
#include <fstream>
#include <cmath>

using namespace std;

class StringSet {
private:
    set<string> uniqueWords;
    int numOfWords = 0;
public:
    // 2 constructors
    StringSet() = default;
    explicit StringSet(ifstream&);
    explicit StringSet(string);

    // Functions
    void addString(string);
    void removeString(string);
    void clearSet();
    int getNumOfWords();
    void printWordSet();
    double computeSimilarity(const StringSet&);

    // Overloaded Operators
    StringSet operator+(const StringSet&);
    StringSet operator*(const StringSet&);

};


#endif //TASK3_STRINGSET_H
