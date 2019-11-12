#include "WordCount.h"
#include <iostream>

using namespace std;

int main()
{
    WordCount w;
    cout << w.incrWordCount("Hello") << endl;
    cout << w.getNumUniqueWords() << endl;
    cout << w.getTotalWords() << endl;
    cout << w.getWordCount("Hello") << endl;
    cout << w.incrWordCount("hello") << endl;
    cout << w.getNumUniqueWords() << endl;
    cout << w.getTotalWords() << endl;
    cout << w.getWordCount("Hello") << endl;
    cout << w.incrWordCount("Hi") << endl;
    cout << w.getNumUniqueWords() << endl;
    cout << w.getTotalWords() << endl;
    cout << w.getWordCount("Hello") << endl;
}