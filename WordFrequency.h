/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 13: Assignment
22 Nov 2024
Defines Word Frequency structure and constants.
Manages storage of word-frequency pairs.
-------------------------------------------------- */

#ifndef WORDFREQUENCY_H
#define WORDFREQUENCY_H

#include <string>  // String handling

using namespace std;

const int MAX_WORDS = 5000;

struct WordFrequency {
    string word{};
    int count{ 0 };
};

#endif