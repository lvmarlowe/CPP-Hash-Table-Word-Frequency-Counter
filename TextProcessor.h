/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 13: Assignment
22 Nov 2024
Implements text processing functionality.
Handles input text tokenization and cleaning.
-------------------------------------------------- */

#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include "WordFrequency.h"  // Word frequency data structure
#include <string>           // String operations

using namespace std;

class ProgramManager;  // Forward declaration

class TextProcessor {
public:
    TextProcessor();

private:
    friend class ProgramManager;
    static const int BORDER_LENGTH = 80;
    string quote;
    string wordArray[MAX_WORDS];
    int wordCount{ 0 };

    // Text processing operations
    void removePunctuation(string& word);
    void toLowerCase(string& word);
    void tokenizeText();
};

#endif