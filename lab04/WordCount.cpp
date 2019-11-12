// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const
{
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++)
	{
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const
{
	// STUB.
	int numWords = 0;
	for (int i = 0; i < CAPACITY; i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			numWords += table[i][j].second;
		}
	}
	return numWords;
}

int WordCount::getNumUniqueWords() const
{
	// STUB
	int numWords = 0;
	for (int i = 0; i < CAPACITY; i++)
	{
		numWords += table[i].size();
	}
	return numWords;
}

int WordCount::getWordCount(std::string word) const
{
	// STUB
	string strippedWord = stripWord(word);
	string upperCaseWord = "";
	for (int i = 0; i < strippedWord.size(); i++)
	{
		upperCaseWord = toupper(strippedWord[i]);
	}
	int index = hash(upperCaseWord);

	vector<pair<string, size_t> > temp = table[index];

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp.at(i).first == upperCaseWord)
		{
			return temp.at(i).second;
		}
	}
	return 0;
}

int WordCount::incrWordCount(std::string word)
{
	string strippedWord = stripWord(word);
	string upperCaseWord = "";
	for (int i = 0; i < strippedWord.size(); i++)
	{
		upperCaseWord = toupper(strippedWord[i]);
	}
	int index = hash(upperCaseWord);

	for (int i = 0; i < table[index].size(); i++)
	{
		if (table[index].at(i).first == upperCaseWord)
		{
			table[index].at(i).second++;
			return table[index].at(i).second;
		}
	}
	table[index].push_back(pair<string, size_t>(upperCaseWord, 1));
	return 1;
}

bool WordCount::isWordChar(char c)
{
	// STUB
	return isalpha(c);
}

std::string WordCount::stripWord(std::string word)
{
	// STUB
	return word;
}
