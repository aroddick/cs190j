// WordCount.cpp

#include "WordCount.h"
#include <vector>

using namespace std;

bool sortBySecond(const pair<string, size_t> &a, const pair<string, size_t> &b) {
	if (a.second == b.second) {
		return (a.first < b.first);
	}
	return (a.second > b.second);
}

// Default constructor
WordCount::WordCount() {}

size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	size_t totalWords = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		if (table[i].size() > 0) {
			for (size_t j = 0; j < table[i].size(); j++) {
				totalWords += table[i][j].second;
			}
		}
	}
	return totalWords;
}

int WordCount::getNumUniqueWords() const {
	size_t totalUniqueWords = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		totalUniqueWords += table[i].size();
	}
	return totalUniqueWords;
}

int WordCount::getWordCount(std::string word) const {
	string strippedWord = stripWord(word);

	string hashWord = "";
	for (size_t i = 0; i < strippedWord.size(); i++) {
		hashWord += toupper(strippedWord.at(i));
	}

	size_t hashIndex = hash(hashWord);

	vector<pair<string, size_t> > v = table[hashIndex];

	for (size_t i = 0; i < table[hashIndex].size(); i++) {
		if (table[hashIndex][i].first == hashWord) {
			return table[hashIndex][i].second;
		}
	}
	return 0;
}
	

int WordCount::incrWordCount(std::string word) {
	string strippedWord = stripWord(word);

	string hashWord = "";
	for (size_t i = 0; i < strippedWord.size(); i++) {
		hashWord += toupper(strippedWord.at(i));
	}

	if (hashWord == "") {
		return 0;
	}

	size_t hashIndex = hash(hashWord);

	for (size_t i = 0; i < table[hashIndex].size(); i++) {
		if (table[hashIndex][i].first == hashWord) {
			table[hashIndex][i] =
				pair<string, size_t>(hashWord, table[hashIndex][i].second + 1);
			return table[hashIndex][i].second;
		}
	}
	table[hashIndex].push_back(pair<string, size_t>(hashWord, 1));
	return 1;
}


bool WordCount::isWordChar(char c) {
	return
    (c >=65 && c <= 90) ||	// upper case
    (c >=97 && c <= 122);	// lower case
}


std::string WordCount::stripWord(std::string word) {

	//char firstChar = ' ';
	string firstString = "";
	int frontIndex = 0;
	// make sure the first char is alpha
	for (size_t i = 0; i < word.size(); i++) {
		frontIndex = i;
		if (isWordChar(word.at(i))) {
			firstString = word.at(i);
			break;
		}
	}

	// work backwards to make sure last char is alpha
	//char lastChar = ' ';
	int endIndex = word.size() - 1;
	string endString = "";
	for (int i = word.size() - 1; i > frontIndex; i--) {
		endIndex = i;
		if (isWordChar(word.at(i))) {
			endString = word.at(i);
			break;
		}
	}

	// construct middle string
	string strippedWord = "";
	for (int i = frontIndex + 1; i < endIndex; i++) {
		if (isWordChar(word.at(i)) || word.at(i) == 45 || word.at(i) == 39) {
			strippedWord += word.at(i);
		}
	}

	// put the first, end, and strippedWord together
	if (firstString != "") {
		strippedWord.insert(0, firstString);
	}
	if (endString != "") {
		strippedWord.insert(strippedWord.size(), endString);
	}

	return strippedWord;
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	vector<std::pair<std::string, size_t> > sorted;
	for (int i = 0; i < CAPACITY; i++) {
		for (int j = 0; j < table[i].size(); j++) {
			sorted.push_back(table[i][j]);
		}
	}
	std::sort(sorted.begin(), sorted.end());
	for (int i = 0; i < sorted.size(); i++) {
		out << sorted.at(i).first << "," << sorted.at(i).second << "\n";
	}

	return;
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	vector<std::pair<std::string, size_t> > sorted;
	for (int i = 0; i < CAPACITY; i++) {
		for (int j = 0; j < table[i].size(); j++) {
			sorted.push_back(table[i][j]);
		}
	}
	std::sort(sorted.begin(), sorted.end(), sortBySecond);
	for (int i = 0; i < sorted.size(); i++) {
		out << sorted.at(i).first << "," << sorted.at(i).second << "\n";
	}

	return;
}

void WordCount::addAllWords(std::string text) {
	size_t previous = 0;
	for (size_t i = 1; i <= text.length(); i++) {

		if ((i == text.length()) || (text[i] == ' ') || (text[i] == '\n')) {
			string token = text.substr(previous, i - previous);
			incrWordCount(token);
			previous = i + 1;
		}

	}
	return;
}
