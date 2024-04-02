#include <iostream>
#include <vector>
#include <string>
#include "AbstractFile.h"

using namespace std;

class TextFile: public AbstractFile {
public:
    TextFile(string newName);
    unsigned int getSize();
    string getName();
    int write(vector<char> newVect);
    int append(vector<char> addtlVect);
    void read();
private:
    string name;
    vector<char> contents;
};