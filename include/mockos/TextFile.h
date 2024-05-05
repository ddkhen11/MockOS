#ifndef MOCKOS_TEXTFILE_H
#define MOCKOS_TEXTFILE_H

#include <iostream>
#include <vector>
#include <string>
#include "AbstractFile.h"

using namespace std;

class TextFile : public AbstractFile {
public:
    TextFile(string newName);

    unsigned int getSize() override;

    string getName() override;

    int write(vector<char> newVect) override;

    int append(vector<char> addtlVect) override;

    vector<char> read() override;

    void accept(AbstractFileVisitor *afv) override;

    AbstractFile *clone(string newName) override;

private:
    string name;
    vector<char> contents;
};

#include "AbstractFileVisitor.h"

#endif //MOCKOS_TEXTFILE_H