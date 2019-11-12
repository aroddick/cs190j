#include "WordCount.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    WordCount wc;
    string test1 = "\nTh)($e\nqui^&ck $&@#*#*&$  bro*^$%wn fo(&$^&x \n ju(&mp*^ed ov^%$#er the\nblah blah\n blah";
    wc.addAllWords(test1);
    cout << wc.getTotalWords() << endl;
    cout << wc.getWordCount("blah") << endl;
    cout << wc.getWordCount("The") << endl;
    cout << wc.getWordCount("quick") << endl;
    cout << wc.getWordCount("brown") << endl;
    cout << wc.getWordCount("fox") << endl;
    cout << wc.getWordCount("jumped") << endl;
    cout << wc.getWordCount("the") << endl;
    cout << wc.getWordCount("lazy") << endl;
    std::ostringstream oss1;
    wc.dumpWordsSortedByWord(oss1);
    cout << oss1.str() << endl;
    std::ostringstream oss2;
    wc.dumpWordsSortedByOccurence(oss2);
    cout << oss2.str() << endl;

    string test2 = "Hello my name is Alan and *49I lo*7ve to type and\ndo a lot"
    " of fun things in the sun and I*& am sitting here and I'm enjoying life";
    wc.addAllWords(test2);
    std::ostringstream oss3;
    wc.dumpWordsSortedByWord(oss3);
    cout << oss3.str() << endl;
    std::ostringstream oss4;
    wc.dumpWordsSortedByOccurence(oss4);
    cout << oss4.str() << endl;

}