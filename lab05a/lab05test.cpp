#include "WordCount.h"
#include <iostream>
using namespace std;

int main() {
    WordCount wc;
    string test = " The quick  brown fox \n jumped over the\nblah blah\n blah";
    wc.addAllWords(test);
    cout << wc.getTotalWords() << endl;
    cout << wc.getWordCount("blah") << endl;
    cout << wc.getWordCount("The") << endl;
    cout << wc.getWordCount("quick") << endl;
    cout << wc.getWordCount("brown") << endl;
    cout << wc.getWordCount("fox") << endl;
    cout << wc.getWordCount("jumped") << endl;
    cout << wc.getWordCount("the") << endl;
    cout << wc.getWordCount("lazy") << endl;
}