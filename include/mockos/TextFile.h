#include <iostream>
#include <vector>
#include <string>
#include "AbstractFile.h"

using namespace std;

class TextFile: public AbstractFile {
public:
    TextFile(string newName);
    unsigned int getSize() override;
    string getName() override;
    int write(vector<char> newVect) override;
    int append(vector<char> addtlVect) override;
    void read() override;
private:
    string name;
    vector<char> contents;
};