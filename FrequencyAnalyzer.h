/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 13: Assignment
22 Nov 2024
Implements word frequency analysis functionality.
Processes and sorts word frequency data using hash table.
-------------------------------------------------- */

#ifndef FREQUENCYANALYZER_H
#define FREQUENCYANALYZER_H

#include "WordFrequency.h"  // Word frequency data structure
#include <unordered_map>    // Hash table implementation
#include <string>           // String handling

using namespace std;

class ProgramManager;  // Forward declaration

class FrequencyAnalyzer {
public:
    FrequencyAnalyzer() = default;

private:
    friend class ProgramManager;
    unordered_map<string, int> wordFrequencies;  // Hash table for word counts
    WordFrequency frequencyArray[MAX_WORDS];     // Array for sorted output

    // Analysis operations
    void sortByFrequency();
    void hashToArray();
    void analyzeWords(const string words[], int wordCount);
    void getSortedFrequencies(WordFrequency wordFrequencies[], int arraySize) const;
};

#endif