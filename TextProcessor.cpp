/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 13: Assignment
22 Nov 2024
Implements text processing operations.
Manages text cleaning and tokenization.
-------------------------------------------------- */

#include "TextProcessor.h"  // Local text processor declarations
#include <fstream>          // File input operations
#include <sstream>          // String stream processing
#include <iostream>         // Console output

using namespace std;

// Opens and reads input file for analysis
// Expects Quote.txt to be in the same directory as executable
TextProcessor::TextProcessor() : wordCount(0) {
    ifstream inFile("Quote.txt");
    if (!inFile) {
        string border(BORDER_LENGTH, '=');
        cout << "\n" << border << "\n"
            << "ERROR: Cannot open Quote.txt. Ensure it is in the same directory as the program.\n"
            << border << "\n";
        exit(1);
    }
    string line;
    while (getline(inFile, line)) {
        quote += line + "\n";
    }
    inFile.close();
    tokenizeText();
}

// Removes all punctuation from a word
void TextProcessor::removePunctuation(string& word) {
    string result;
    for (char c : word) {
        if (isalpha(c) || isdigit(c)) {
            result += c;
        }
    }
    word = result;
}

// Converts word to lowercase for consistent comparison
void TextProcessor::toLowerCase(string& word) {
    for (char& c : word) {
        c = tolower(c);
    }
}

// Splits text into individual words and cleans them
void TextProcessor::tokenizeText() {
    stringstream iss(quote);
    string word;
    wordCount = 0;

    while (iss >> word && wordCount < MAX_WORDS) {
        toLowerCase(word);
        removePunctuation(word);
        if (!word.empty()) {
            wordArray[wordCount++] = word;
        }
    }
}