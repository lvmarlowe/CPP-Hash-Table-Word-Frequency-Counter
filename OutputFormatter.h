/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 13: Assignment
22 Nov 2024
Implements output formatting functionality.
Manages display formatting for frequency results.
-------------------------------------------------- */

#ifndef OUTPUTFORMATTER_H
#define OUTPUTFORMATTER_H

#include "WordFrequency.h"  // Word frequency data structure
#include <string>           // String handling

using namespace std;

class ProgramManager;  // Forward declaration

class OutputFormatter {
public:
    OutputFormatter();

private:
    friend class ProgramManager;
    int maxWordLength;
    int maxFrequencyLength;

    // Formatting methods
    string formatHeader() const;
    string formatRow(const string& word, int frequency) const;
    string formatDivider() const;
    void calculateColumnWidths(const WordFrequency wordFrequencies[], int arraySize);
};

#endif