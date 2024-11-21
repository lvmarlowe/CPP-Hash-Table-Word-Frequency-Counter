/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 13: Assignment
22 Nov 2024
Implements program management functionality.
Controls program flow and resource management.
-------------------------------------------------- */

#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#include "TextProcessor.h"      // Text processing operations
#include "FrequencyAnalyzer.h"  // Frequency analysis operations
#include "OutputFormatter.h"    // Output formatting operations
#include <memory>               // Smart pointers

using namespace std;

class ProgramManager {
public:
	ProgramManager();
	~ProgramManager() = default;

private:
	unique_ptr<TextProcessor> textProcessor;
	unique_ptr<FrequencyAnalyzer> frequencyAnalyzer;
	unique_ptr<OutputFormatter> outputFormatter;
	static const int BORDER_LENGTH = 80;

	// Program operations
	void run();
	string createBorder(char symbol) const;
	void displayWelcomeMessage() const;
	void displayExitMessage() const;
	void performAnalysis();
	void displayResults() const;
};

#endif