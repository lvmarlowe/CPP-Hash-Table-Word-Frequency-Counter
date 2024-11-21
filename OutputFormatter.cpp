/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 13: Assignment
22 Nov 2024
Implements output formatting operations.
Creates formatted display of frequency results.
-------------------------------------------------- */

#include "OutputFormatter.h"  // Local output formatter declarations
#include <algorithm>          // max() function

using namespace std;

OutputFormatter::OutputFormatter() : maxWordLength(0), maxFrequencyLength(0) {}

// Determines maximum widths needed for word and frequency columns
void OutputFormatter::calculateColumnWidths(const WordFrequency wordFrequencies[], int arraySize) {
    maxWordLength = 0;
    maxFrequencyLength = 0;

    for (int i = 0; i < arraySize; i++) {
        int wordLen = static_cast<int>(wordFrequencies[i].word.length());
        int freqLen = static_cast<int>(to_string(wordFrequencies[i].count).length());

        maxWordLength = max(maxWordLength, wordLen);
        maxFrequencyLength = max(maxFrequencyLength, freqLen);
    }
}

// Creates formatted header row for frequency table
string OutputFormatter::formatHeader() const {
    int wordColWidth = max(maxWordLength, 4);
    int freqColWidth = max(maxFrequencyLength, 9);

    string header = "| Word";
    header += string(wordColWidth - 4, ' ');
    header += " | Frequency";
    header += string(max(0, freqColWidth - 9), ' ');
    header += " |";

    return header;
}

// Creates formatted data row for word and its frequency
string OutputFormatter::formatRow(const string& word, int frequency) const {
    string row = "| " + word;
    row += string(maxWordLength - word.length() + 1, ' ');

    string freqStr = to_string(frequency);
    row += "| " + freqStr;
    row += string(maxFrequencyLength - freqStr.length() + 1, ' ');
    row += "|";

    return row;
}

// Creates divider line for table formatting
string OutputFormatter::formatDivider() const {
    string divider = "+";
    divider += string(maxWordLength + 2, '-');
    divider += "+";
    divider += string(maxFrequencyLength + 2, '-');
    divider += "+";
    return divider;
}