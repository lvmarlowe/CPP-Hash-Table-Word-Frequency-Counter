/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 13: Assignment
22 Nov 2024
Implements program management operations.
Controls program execution and display.
-------------------------------------------------- */

#include "ProgramManager.h"  // Local program manager declarations
#include <iostream>          // Console output
#include <memory>            // Smart pointer implementations

using namespace std;

// Initializes program components and starts execution
ProgramManager::ProgramManager() {
    run();
}

// Creates decorative border for output formatting
string ProgramManager::createBorder(char symbol) const {
    return string(BORDER_LENGTH, symbol);
}

// Displays program welcome message
void ProgramManager::displayWelcomeMessage() const {
    cout << createBorder('=') << "\n"
        << "Word Frequency Counter\n"
        << createBorder('-') << "\n"
        << "This program stores the frequency count of words\n"
        << "in an excerpt from H.G. Wells's 'War of the Worlds.'\n"
        << createBorder('=') << "\n\n";
}

// Displays program exit message
void ProgramManager::displayExitMessage() const {
    cout << "\n" << createBorder('=') << "\n"
        << "Exiting program.\n"
        << createBorder('-') << "\n"
        << "Thank you for using the Word Frequency Counter.\n"
        << createBorder('=') << "\n";
}

// Performs word frequency analysis on text
void ProgramManager::performAnalysis() {
    frequencyAnalyzer->analyzeWords(textProcessor->wordArray, textProcessor->wordCount);
}

// Displays analyzed frequency results
void ProgramManager::displayResults() const {
    int arraySize = frequencyAnalyzer->wordFrequencies.size();
    auto sortedFrequencies = make_unique<WordFrequency[]>(arraySize);

    frequencyAnalyzer->getSortedFrequencies(sortedFrequencies.get(), arraySize);
    outputFormatter->calculateColumnWidths(sortedFrequencies.get(), arraySize);

    cout << "\nWord Frequency Analysis Results:\n";
    cout << outputFormatter->formatDivider() << '\n';
    cout << outputFormatter->formatHeader() << '\n';
    cout << outputFormatter->formatDivider() << '\n';

    for (int i = 0; i < arraySize; i++) {
        cout << outputFormatter->formatRow(
            sortedFrequencies[i].word,
            sortedFrequencies[i].count) << '\n';
    }

    cout << outputFormatter->formatDivider() << '\n';
    cout << "\nTotal Unique Words: " << arraySize << '\n';
}

// Runs program
void ProgramManager::run() {
    textProcessor = make_unique<TextProcessor>();
    frequencyAnalyzer = make_unique<FrequencyAnalyzer>();
    outputFormatter = make_unique<OutputFormatter>();

    displayWelcomeMessage();
    performAnalysis();
    displayResults();
    displayExitMessage();
}
