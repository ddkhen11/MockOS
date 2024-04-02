#include <iostream>
#include <vector>
#include <string>
#include "mockos/TextFile.h"

using namespace std;

int main () {
    cout << "Call methods by derived class" << endl;
    TextFile textFile("test");
    vector<char> test1 = {'p', 'r', 'i', 'z', 'e'};
    vector<char> test2 = {};
    vector<char> test3 = {'p', ' ', 'p'};
    textFile.write(test1);
    textFile.read();
    textFile.append(test2);
    textFile.read();
    textFile.write(test3);
    textFile.read();

    cout << endl;
    cout << "Call methods by aliased abstract class" << endl;
    AbstractFile* p;
    p = &textFile;
    p->write(test2); // Make textFile.contents blank again
    p->write(test1);
    p->read();
    p->append(test2);
    p->read();
    p->write(test3);
    p->read();
}