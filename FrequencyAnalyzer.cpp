/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 13: Assignment
22 Nov 2024
Implements frequency analysis operations using hash table.
Manages word counting and sorting.
-------------------------------------------------- */

#include "FrequencyAnalyzer.h"  // Local frequency analyzer declarations
#include <algorithm>            // sort() algorithm

using namespace std;

// Orders words in descending order by frequency count and then alphabetically
void FrequencyAnalyzer::sortByFrequency() {
    int size = wordFrequencies.size();
    sort(frequencyArray, frequencyArray + size,
        [](const WordFrequency& a, const WordFrequency& b) {
            return (a.count != b.count) ? (a.count > b.count) : (a.word < b.word);
        });
}

// Converts hash table entries to array format for sorting
void FrequencyAnalyzer::hashToArray() {
    int index = 0;

    // Iterate through hash table and populate array
    for (const auto& pair : wordFrequencies) {
        frequencyArray[index].word = pair.first;
        frequencyArray[index].count = pair.second;
        index++;
    }
}

// Copies sorted frequencies to output array
void FrequencyAnalyzer::getSortedFrequencies(WordFrequency wordFrequencies[], int arraySize) const {
    for (int i = 0; i < arraySize && i < static_cast<int>(this->wordFrequencies.size()); i++) {
        wordFrequencies[i] = frequencyArray[i];
    }
}

// Processes word array to count frequencies using hash table
void FrequencyAnalyzer::analyzeWords(const string words[], int wordCount) {

    // Clear existing hash table
    wordFrequencies.clear();

    // Count word frequencies using hash table
    for (int i = 0; i < wordCount; i++) {
        wordFrequencies[words[i]]++;
    }

    // Convert hash table to array and sort
    hashToArray();
    sortByFrequency();
}