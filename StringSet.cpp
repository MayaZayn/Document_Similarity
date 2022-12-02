#include "StringSet.h"

#include <utility>

StringSet::StringSet(ifstream& file) {
    string content;
    while (getline(file, content)) {
        for (int i = 0; i < content.size(); ++i) {
            string word = "";
            while (isalnum(content[i]) && i < content.size()) {
                word += tolower(content[i++]);
            }
            uniqueWords.insert(word);
        }
    }
}

StringSet::StringSet(string str) {
    this->addString(move(str));
}

void StringSet::addString(string str) {
    for (int i = 0; i < str.size(); ++i) {
        string word = "";
        while (isalnum(str[i]) && i < str.size()) {
            word += tolower(str[i++]);
        }
        if (!word.empty()) {
            if (!uniqueWords.count(word))
                numOfWords++;
            uniqueWords.insert(word);
        }
    }
}

void StringSet::removeString(string str) {
    for (int i = 0; i < str.size(); ++i) {
        string word = "";
        while (isalnum(str[i]) && i < str.size()) {
            word += tolower(str[i++]);
        }
        if (!word.empty()) {
            if (uniqueWords.count(word)) {
                numOfWords--;
                uniqueWords.erase(word);
            }
        }
    }

//    if (uniqueWords.count(str)) {
//        uniqueWords.erase(str);
//        numOfWords--;
//    }
}

void StringSet::clearSet() {
    if (!uniqueWords.empty())
        uniqueWords.clear();
    numOfWords = 0;
}

int StringSet::getNumOfWords() {
    return numOfWords;
}

void StringSet::printWordSet() {
    if (!uniqueWords.empty()) {
        cout << "Words in Set:\n";
        for (auto &word: uniqueWords)
            cout << word << ' ';
        cout << endl;
    } else {
        cout << "The word set is empty!\n";
    }
}

double StringSet::computeSimilarity(const StringSet & query) {
    int common = 0;

    if ((this->uniqueWords.empty() && !query.uniqueWords.empty()) ||
            (!this->uniqueWords.empty() && query.uniqueWords.empty()))
        return 0;
    else if (this->uniqueWords.empty() && query.uniqueWords.empty())
        return 1;

    if (query.numOfWords < this->numOfWords) {
        for (auto & word : query.uniqueWords)
            if (this->uniqueWords.count(word))
                common++;
    } else {
        for (auto & word : this->uniqueWords)
            if (query.uniqueWords.count(word))
                common++;
    }
    return ((common) / (sqrt(this->numOfWords) * sqrt(query.numOfWords)));
}

StringSet StringSet::operator+(const StringSet & query) {
    StringSet Union;
    for (auto & word : this->uniqueWords) {
        Union.uniqueWords.insert(word);
    }
    for (auto & word : query.uniqueWords) {
        Union.uniqueWords.insert(word);
    }
    return Union;
}

StringSet StringSet::operator*(const StringSet & query) {
    StringSet Intersection;
    for (auto & word : this->uniqueWords) {
        if (query.uniqueWords.count(word))
            Intersection.uniqueWords.insert(word);
    }
    return Intersection;
}

